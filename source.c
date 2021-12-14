// X11 Bell
// Copyright (c) 2021 Jovan Lanik

#include <stdlib.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/XKBlib.h>

int main(int argc, char *argv[]) {
	Display *display = XOpenDisplay(NULL);
	if(!display) exit(EXIT_FAILURE);

	int major = XkbMajorVersion;
	int minor = XkbMinorVersion;

	if(!XkbLibraryVersion(&major, &minor)) exit(EXIT_FAILURE);

	major = XkbMajorVersion;
	minor = XkbMinorVersion;
	int xkb_event_base;

	if(!XkbQueryExtension(display, NULL, &xkb_event_base, NULL, &major, &minor))
		exit(EXIT_FAILURE);

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
		if(pid == -1) exit(EXIT_FAILURE);
		else if(pid == 0 && argc > 1) {
			execvp(argv[1], &argv[1]);
			exit(EXIT_FAILURE);
		}
	}
}

