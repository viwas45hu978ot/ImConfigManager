
# ImConfigManager

ImConfigManger is a simple lightweight config editor designed for BepInEx configs

If you find a bug or have a good idea to something that could be added post an issue or write to me on discord `viwas45hu978ot#5747`

Heavily inspired by JJoe's config manager

## Features

- Custom file browser
- Fast save and load times
- Low memory usage
- Multiple styles
- Custom style editor

## Installation

Download the latest release and unzip the zip then run ImConfig.exe

## Screenshots

![App Screenshot](https://github.com/viwas45hu978ot/ImConfigManager/raw/main/pic1.png)
![App Screenshot](https://github.com/viwas45hu978ot/ImConfigManager/raw/main/pic2.png)
![App Screenshot](https://github.com/viwas45hu978ot/ImConfigManager/raw/main/pic3.png)
    
## Style Editor
The style editor works by modifying the style.toml file

Here is an example of a simple style
```
# Variables

[alpha]
    value = 1

[window.padding]
    value = [8, 8]

[window.rounding]
    value = 10

[window.border.size]
    value = 1

[window.min.size]
    value = [32, 32]

[window.title.align]
    value = [0.0, 0.5]

[window.menu.button.position]
    value = "left"

[child.rounding]
    value = 0

[child.border.size]
    value = 1

[popup.rounding]
    value = 0

[popup.border.size]
    value = 1

[frame.padding]
    value = [4, 3]

[frame.rounding]
    value = 0

[frame.border.size]
    value = 0

[item.spacing]
    value = [8, 4]

[item.inner.spacing]
    value = [4, 4]

[touch.extra.padding]
    value = [0, 0]

[indent.spacing]
    value = 21

[columns.min.spacing]
    value = 6

[scrollbar.size]
    value = 14

[scrollbar.rounding]
    value = 9

[grab.min.size]
    value = 10

[grab.rounding]
    value = 0

[tab.rounding]
    value = 4

[tab.border.size]
    value = 0

[button.text.align]
    value = [0.5, 0.5]

[selectable.text.align]
    value = [0, 0]

[display.window.padding]
    value = [19, 19]

[display.safe.area.padding]
    value = [3, 3]

[mouse.cursor.scale]
    value = 1

[anti.aliased.lines]
    value = true

[anti.aliased.fill]
    value = true

[curve.tessellation.tol]
    value = 1.25

# Colors

[text]
    value = [1.00, 1.00, 1.00, 1.00]

    [text.disabled]
        value = [0.50, 0.50, 0.50, 1.00]

[window.bg]
    value = [0.06, 0.06, 0.06, 0.94]

[child.bg]
    value = [0.00, 0.00, 0.00, 0.00]

[popup.bg]
    value = [0.08, 0.08, 0.08, 0.94]

[border]
    value = [0.43, 0.43, 0.50, 0.50]

    [border.shadow]
        value = [0.00, 0.00, 0.00, 0.00]

[frame.bg]
    value = [0.16, 0.29, 0.48, 0.96]

    [frame.bg.hovered]
        value = [0.26, 0.59, 0.98, 0.40]

    [frame.bg.active]
        value = [0.26, 0.59, 0.98, 0.67]

[title.bg]
    value = [0.04, 0.04, 0.04, 1.00]

    [title.bg.active]
        value = [0.16, 0.29, 0.48, 1.00]

    [title.bg.collapsed]
        value = [0.00, 0.00, 0.00, 0.51]

[menu.bar.bg]
    value = [0.14, 0.14, 0.14, 1.00]

[scrollbar.bg]
    value = [0.02, 0.02, 0.02, 0.53]

[scrollbar.grab]
    value = [0.31, 0.31, 0.31, 1.00]

    [scrollbar.grab.hovered]
        value = [0.41, 0.41, 0.41, 1.00]

    [scrollbar.grab.active]
        value = [0.51, 0.51, 0.51, 1.00]

[check.mark]
    value = [0.26, 0.59, 0.98, 1.00]

[slider.grab]
    value = [0.24, 0.52, 0.88, 1.00]

    [slider.grab.active]
        value = [0.26, 0.59, 0.98, 1.00]

[button]
    value = [0.26, 0.59, 0.98, 0.40]

    [button.hovered]
        value = [0.26, 0.59, 0.98, 1.00]

    [button.active]
        value = [0.06, 0.53, 0.98, 1.00]

[header]
    value = [0.26, 0.59, 0.98, 0.31]

    [header.hovered]
        value = [0.26, 0.59, 0.98, 0.80]

    [header.active]
        value = [0.26, 0.59, 0.98, 1.00]

[separator]
    value = [0.43, 0.43, 0.50, 0.50]

    [separator.hovered]
        value = [0.10, 0.40, 0.75, 0.78]

    [separator.active]
        value = [0.10, 0.40, 0.75, 1.00]

[resize.grip]
    value = [0.26, 0.59, 0.98, 0.25]

    [resize.grip.hovered]
        value = [0.26, 0.59, 0.98, 0.67]

    [resize.grip.active]
        value = [0.26, 0.59, 0.98, 0.95]

[tab]
    value = [0.26, 0.59, 0.98, 0.31]

    [tab.hovered]
        value = [0.26, 0.59, 0.98, 0.80]

    [tab.active]
        value = [0.26, 0.59, 0.98, 1.00]

    [tab.unfocused]
        value = [0.26, 0.59, 0.98, 0.31]

        [tab.unfocused.active]
            value = [0.26, 0.59, 0.98, 1.00]

[plot.lines]
    value = [0.61, 0.61, 0.61, 1.00]

    [plot.lines.hovered]
        value = [1.00, 0.43, 0.35, 1.00]

[plot.histogram]
    value = [0.90, 0.70, 0.00, 1.00]

    [plot.histogram.hovered]
        value = [1.00, 0.60, 0.00, 1.00]

[text.selected.bg]
    value = [0.26, 0.59, 0.98, 0.35]

[drag.drop.target]
    value = [1.00, 1.00, 0.00, 0.90]

[nav.highlight]
    value = [0.26, 0.59, 0.98, 1.00]

[nav.windowing.highlight]
    value = [1.00, 1.00, 1.00, 0.70]

[nav.windowing.dim.bg]
    value = [0.80, 0.80, 0.80, 0.20]

[modal.window.dim.bg]
    value = [0.80, 0.80, 0.80, 0.35]
``` 
## Acknowledgements

 - [Dear ImGui](https://github.com/ocornut/imgui)


