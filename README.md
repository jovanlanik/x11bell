# X11 Bell
A simple replacement for the `x11-bell` pulseaudio module.
## Usage
`x11bell <command> [<args>]`
### Examples
`x11bell pactl play-sample x11-bell` (don't forget to load a sample in the pulseaudio or pipewire config)

`x11bell notify-send -a X11 Bell`
## Building
`make`
### Dependencies
- libX11
