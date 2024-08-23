/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once
/* Select hand configuration */
#define MASTER_LEFT

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT                             \
  500U // Timeout window in ms in which the double tap can occur.
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 3000

#define VIAL_KEYBOARD_UID                                                      \
  { 0x47, 0x97, 0x7E, 0x32, 0xC9, 0xAC, 0x13, 0xF3 }

#define VIAL_UNLOCK_COMBO_ROWS                                                 \
  { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS                                                 \
  { 0, 1 }

#define DYNAMIC_KEYMAP_LAYER_COUNT 6
#define VIAL_TAP_DANCE_ENTRIES 4
#define VIAL_COMBO_ENTRIES 16

// Config to make MOD TAP keys more responsive
#define PERMISIVE_HOLD

// Disable some of the features that we do not use to save space
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_MUSIC_MODE
#define LAYER_STATE_8BIT
