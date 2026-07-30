```markdown
# taranctl

**taranctl** is the central system management utility for **TARAN OS**.

Written as a POSIX-compliant shell script for BusyBox `ash`, it provides a simple and consistent interface for managing hardware, networking, packages, the firewall, and other operating system services without exposing unnecessary implementation details.

Rather than requiring users to remember Alpine Linux commands and configuration files, `taranctl` presents a stable, human-friendly command interface that remains consistent as TARAN OS evolves.

---

## Philosophy

TARAN OS is built upon Alpine Linux while providing a coherent desktop operating system designed for simplicity, performance and security.

```

Applications
↑
TARAN Shell
↑
TARAN Services
↑
Alpine Linux

````

The layers have distinct responsibilities:
--------------------------------------------------------------------------------------------------------------------
|      Layer         |                                       Purpose                                               |
|--------------------|---------------------------------------------------------------------------------------------|
| **Applications**   | User applications such as HissLAN, Klasker, TARAN OS Files and future software.             |
| **TARAN Shell**    | The desktop session, launcher, panel, settings and user experience.                         |
| **TARAN Services** | System utilities including `taranctl`, networking, firewall management and installer logic. |
| **Alpine Linux**   | Linux kernel, BusyBox, musl libc, OpenRC, `apk` and the core operating system.              |
--------------------------------------------------------------------------------------------------------------------

---

## Goals

- POSIX shell compatible (BusyBox `ash`)
- No Python dependency
- No systemd dependency
- OpenRC native
- Lightweight and easy to audit
- Human-friendly command interface
- Stable command-line API
- Suitable for scripting and automation

---

## Planned Commands

### Hardware

```bash
taranctl hardware detect
taranctl hardware firmware
````

Detects installed hardware, identifies drivers and installs the appropriate firmware packages.

---

### Network

```bash
taranctl network status
taranctl network wifi scan
taranctl network wifi connect <ssid>
taranctl network wifi disconnect
```

Provides a simplified interface for managing wired and wireless networking.

---

### Firewall

```bash
taranctl firewall status
taranctl firewall enable
taranctl firewall disable
taranctl firewall reload
```

Manages the TARAN OS nftables firewall.

---

### Packages

```bash
taranctl packages search <name>
taranctl packages add <package>
taranctl packages remove <package>
taranctl packages update
```

Provides a friendlier interface to Alpine Linux's `apk` package manager.

---

### System

```bash
taranctl system info
taranctl system reboot
taranctl system shutdown
```

Displays system information and performs common administrative tasks.

---

## Design Principles

* Simplicity over complexity.
* One obvious way to perform common administrative tasks.
* Small implementation with minimal dependencies.
* Reuse existing Alpine Linux components whenever possible.
* Hide implementation details without hiding functionality.
* Keep the user interface stable while allowing the internal implementation to evolve.

---

## Future Features

* Hardware detection using `lspci -nnk` and `lsusb`
* Automatic firmware installation
* JSON output mode for automation
* Guided network configuration
* Firewall profile management
* Desktop integration with TARAN Settings
* Installer integration
* Diagnostic reports

---

## Development Status

**Early development**

The command structure is currently being designed while TARAN OS itself is under active development.

---

## License

MIT License.

```
```

