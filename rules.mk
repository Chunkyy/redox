TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes
COMMAND_ENABLE = no
DYNAMIC_TAPPING_TERM_ENABLE = yes
LTO_ENABLE = yes

# Path to this keymap, resolved through the qmk_firmware symlink so git
# commands run against the Chunkyy/redox keymap repo, not qmk_firmware's.
KEYMAP_PATH := $(patsubst %/,%,$(dir $(realpath $(lastword $(MAKEFILE_LIST)))))
KEYMAP_GIT_BRANCH := $(shell git -C $(KEYMAP_PATH) rev-parse --abbrev-ref HEAD 2>/dev/null)
KEYMAP_GIT_COMMIT := $(shell git -C $(KEYMAP_PATH) rev-parse --short HEAD 2>/dev/null)
KEYMAP_GIT_DIRTY := $(shell git -C $(KEYMAP_PATH) status --porcelain 2>/dev/null)

OPT_DEFS += -DFIRMWARE_BRANCH='"$(if $(KEYMAP_GIT_BRANCH),$(KEYMAP_GIT_BRANCH),unknown)"'
OPT_DEFS += -DFIRMWARE_COMMIT='"$(if $(KEYMAP_GIT_COMMIT),$(KEYMAP_GIT_COMMIT),unknown)$(if $(KEYMAP_GIT_DIRTY),-uncommitted,)"'
