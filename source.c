// X11 Bell
// Copyright (c) 2021 Jovan Lanik

#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/XKBlib.h>

int main(int argc, char *argv[]) {
	if(argc < 2) return 1;

	Display *display = XOpenDisplay(NULL);
	if(!display) return 1;

	int major = XkbMajorVersion;
	int minor = XkbMinorVersion;
	if(!XkbLibraryVersion(&major, &minor)) return 1;

	major = XkbMajorVersion;
	minor = XkbMinorVersion;
	int xkb_event_base;
	if(!XkbQueryExtension(display, NULL, &xkb_event_base, NULL, &major, &minor))
		return 1;

	XkbSelectEvents(display, XkbUseCoreKbd, XkbBellNotifyMask, XkbBellNotifyMask);

	unsigned int auto_ctrls, auto_values;
	auto_ctrls = auto_values = XkbAudibleBellMask;
	XkbSetAutoResetControls(display, XkbAudibleBellMask, &auto_ctrls, &auto_values);
	XkbChangeEnabledControls(display, XkbUseCoreKbd, XkbAudibleBellMask, 0);

	while(1) {
		XEvent event;
		XNextEvent(display, &event);
		if(((XkbEvent *)&event)->any.xkb_type != XkbBellNotify) continue;
		pid_t pid = fork();
		if(pid == 0) execvp(argv[1], &argv[1]);
		else if(pid != -1) continue;
		return 1;
	}
}

