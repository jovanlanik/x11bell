# X11 Bell
A simple replacement for the `x11-bell` pulseaudio module.
## Usage
`$ x11bell <command> [<args>]`
### Examples
- Pulseaudio and Pipewire (don't forget to load sample first): `x11bell pactl play-sample x11-bell`
- ALSA: `x11bell aplay -q ~/.local/bell.wav`
- GStreamer: `x11bell gst-play-1.0 --no-interactive --quiet /usr/share/sounds/freedesktop/stereo/bell.oga`
- D-Bus desktop notification: `x11bell notify-send -a X11 Bell`
## Building
`$ make`
### Dependencies
- libX11
