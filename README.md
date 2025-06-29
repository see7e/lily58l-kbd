---
title: Lily58l configurations
tags:
  - programming
  - setup
use: Documentation
languages: C
dependences: QMK Firmware
---

<details> <summary>Table of Contents 🔖</summary>

- [Lily58l configurations](#lily58l-configurations)
  - [Requirements](#requirements)
  - [Repository Structure](#repository-structure)
  - [Enabling Features](#enabling-features)
  - [Compiling the Firmware](#compiling-the-firmware)
  - [Flashing the Firmware](#flashing-the-firmware)
  - [OLED Configuration](#oled-configuration)
  - [Using User Configurations](#using-user-configurations)
  - [Resources](#resources)

</details>

---

# Lily58l configurations
> [TODO list here](./TODO.md)

## Requirements
Make sure you have installed:
- [QMK Firmware](https://github.com/qmk/qmk_firmware) and [QMK Toolbox](https://qmk.fm/toolbox)

## Repository Structure
A typical `qmk_firmware` folder looks like this:

```
<your-user>/qmk_firmware/
├── keyboards/
│   └── lily58/
│       └── keymaps/
│           └── your_keymap/
│               ├── keymap.c
│               ├── rules.mk
├── users/
│   └── your_user/
│       ├── your_user.c
│       ├── your_user.h
│       └── rules.mk
```

> [!TIP]
> You can put shared code (e.g., OLED animations) in `users/`.

## Enabling Features
Edit your `rules.mk` inside your keymap folder:

```makefile
OLED_ENABLE = yes
OLED_DRIVER_ENABLE = yes
WPM_ENABLE = yes
EXTRAKEY_ENABLE = yes
```

Optional:

```makefile
RGBLIGHT_ENABLE = yes
LTO_ENABLE = yes
```

## Compiling the Firmware
Build your firmware with:

```bash
qmk compile -kb lily58 -km your_keymap
```
- `-kb` = keyboard (`lily58/rev1` in my case)
- `-km` = keymap folder name (`your_keymap`)

## Flashing the Firmware
- Put the keyboard into bootloader mode:
	- Press the reset button (or use a key combo)
	- OR short the reset and ground pads
- OR use the `auto-flash` option at the Toolbox app

If flashing manually:

```bash
qmk flash -kb lily58 -km your_keymap
```

Follow the instructions shown by the CLI.

## OLED Configuration
To display information on the OLED, you must:
- Enable `OLED_ENABLE` and `OLED_DRIVER_ENABLE` in `rules.mk`
- Implement the `oled_task_user()` function in `keymap.c`

Example snippet:

```c
bool oled_task_user(void) {
    oled_write_ln("Lily58", false);
    oled_write_ln("Layer:", false);
    oled_write(get_u8_str(get_highest_layer(layer_state), ' '), false);
    return false;
}
```

> [!NOTE]
> The animations here at `users/see7e` are a adapted version of [snowe keymap/userspace and Ocean Dream animation by snowe2010 · Pull Request #12477 · qmk/qmk_firmware](https://github.com/qmk/qmk_firmware/pull/12477/files#diff-e4ae46858fb19ccbfacaec40c590a1ab217231618b5c78d73e79c7de5c8159cb) you may see the [original animation]([Ocean Dream - OLED animation for QMK keyboards - YouTube](https://www.youtube.com/watch?v=cPOcOQ7fTjA)) for reference. You can see [his installation guide]([qmk_firmware/users/snowe/readme_ocean_dream.md at master · snowe2010/qmk_firmware](https://github.com/snowe2010/qmk_firmware/blob/master/users/snowe/readme_ocean_dream.md)). 

## Using User Configurations
If you want shared logic across keyboards:
- Create a folder: `users/yourname`
- Put `yourname.c`, `yourname.h`, and `rules.mk` there
- In `rules.mk`:
    ```makefile
    SRC += $(USER_PATH)/oled_setup.c
    ```
- In `keymap.c`:
    ```c
    #include "yourname.h"
    ```

When you build `-km yourname`, QMK automatically includes the user code.

## Resources
- [Lily58 Build Guide](https://github.com/kata0510/Lily58)
- [QMK Docs](https://docs.qmk.fm/)
- [QMK Configurator](https://config.qmk.fm/#/lily58)
