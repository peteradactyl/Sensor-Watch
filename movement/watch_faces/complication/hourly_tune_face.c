/*
 * MIT License
 *
 * Copyright (c) 2024 <#author_name#>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdlib.h>
#include <string.h>
#include "hourly_tune_face.h"

// TODO
// Set a default signal tune (or must it be 0?)
// Simplify files so that this pulls from movement_custom_signal_tunes.h
// Export active_tune so that movement_config or other files can change the variable.

int tune_number = 0;

//01
static void SIGNAL_TUNE_DEFAULT() {
    static const int8_t _TUNE_DEFAULT[] = {
        BUZZER_NOTE_C8, 5,
        BUZZER_NOTE_REST, 6,
        BUZZER_NOTE_C8, 5,
        0
    };
    watch_buzzer_play_sequence((int8_t *)_TUNE_DEFAULT, NULL);
}

//02
static void SIGNAL_TUNE_ZELDA_SECRET() {
    static const int8_t _TUNE_ZELDA_SECRET[] = {
        BUZZER_NOTE_G5, 8,
        BUZZER_NOTE_F5SHARP_G5FLAT, 8,
        BUZZER_NOTE_D5SHARP_E5FLAT, 8,
        BUZZER_NOTE_A4, 8,
        BUZZER_NOTE_G4SHARP_A4FLAT, 8,
        BUZZER_NOTE_E5, 8,
        BUZZER_NOTE_G5SHARP_A5FLAT, 8,
        BUZZER_NOTE_C6, 20,
        0
    };
    watch_buzzer_play_sequence((int8_t *)_TUNE_ZELDA_SECRET, NULL);
}

//03
static void SIGNAL_TUNE_MARIO_THEME() {
    static const int8_t _TUNE_MARIO_THEME[] = {
        BUZZER_NOTE_E6, 7,
        BUZZER_NOTE_REST, 2,
        BUZZER_NOTE_E6, 7,
        BUZZER_NOTE_REST, 10,
        BUZZER_NOTE_E6, 7,
        BUZZER_NOTE_REST, 11,
        BUZZER_NOTE_C6, 7,
        BUZZER_NOTE_REST, 1,
        BUZZER_NOTE_E6, 7,
        BUZZER_NOTE_REST, 10,
        BUZZER_NOTE_G6, 8,
        BUZZER_NOTE_REST, 30,
        BUZZER_NOTE_G5, 8,
        0
    };
    watch_buzzer_play_sequence((int8_t *)_TUNE_MARIO_THEME, NULL);
}

//04
static void SIGNAL_TUNE_KIM_POSSIBLE() {
    static const int8_t _TUNE_KIM_POSSIBLE[] = {
        BUZZER_NOTE_G7, 6,
        BUZZER_NOTE_REST, 1,
        BUZZER_NOTE_G4, 3,
        BUZZER_NOTE_REST, 5,
        BUZZER_NOTE_G7, 6,
        BUZZER_NOTE_REST, 1,
        BUZZER_NOTE_G4, 3,
        BUZZER_NOTE_REST, 5,
        BUZZER_NOTE_A7SHARP_B7FLAT, 6,
        BUZZER_NOTE_REST, 2,
        BUZZER_NOTE_G7, 6,
        0
    };
    watch_buzzer_play_sequence((int8_t *)_TUNE_KIM_POSSIBLE, NULL);
}

//05
static void SIGNAL_TUNE_POKEMON_ITEM() {
    static const int8_t _TUNE_POKEMON_ITEM[] = {
        BUZZER_NOTE_E5, 5,
        BUZZER_NOTE_REST, 1,
        BUZZER_NOTE_E5, 5,
        BUZZER_NOTE_REST, 1,
        BUZZER_NOTE_E5, 5,
        BUZZER_NOTE_REST, 1,
        BUZZER_NOTE_B5, 24,
        0
    };
    watch_buzzer_play_sequence((int8_t *)_TUNE_POKEMON_ITEM, NULL);
}

//06
static void SIGNAL_TUNE_WINCHESTER() {
    static const int8_t _TUNE_WINCHESTER[] = {
        BUZZER_NOTE_A4, 20,
        BUZZER_NOTE_REST, 2,
        BUZZER_NOTE_F4, 20,
        BUZZER_NOTE_REST, 2,
        BUZZER_NOTE_G4, 20,
        BUZZER_NOTE_REST, 2,
        BUZZER_NOTE_C4, 40,
        BUZZER_NOTE_REST, 20,
        BUZZER_NOTE_F4, 20,
        BUZZER_NOTE_REST, 2,
        BUZZER_NOTE_G4, 20,
        BUZZER_NOTE_REST, 2,
        BUZZER_NOTE_A4, 20,
        BUZZER_NOTE_REST, 2,
        BUZZER_NOTE_F4, 40,
        0
    };
    watch_buzzer_play_sequence((int8_t *)_TUNE_WINCHESTER, NULL);
}


void hourly_tune_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(hourly_tune_state_t));
        memset(*context_ptr, 0, sizeof(hourly_tune_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}


void hourly_tune_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    hourly_tune_state_t *state = (hourly_tune_state_t *)context;
    state->active = false;
    // state->active_tune = 2;
    // Handle any tasks related to your watch face coming on screen.
}

static void _hourly_tune_face_update_lcd(hourly_tune_state_t *state) {
    if (state->tune == 0) {
        watch_display_string("Tn 1Beep  ", 0);
        if (state->active_tune == state->tune) {
            watch_set_indicator(WATCH_INDICATOR_BELL);
            tune_number = 0;
            }
        else {
            watch_clear_indicator(WATCH_INDICATOR_BELL);
        }
    }
    else if (state->tune == 1) {
        watch_display_string("Tn 2SECRET", 0);
        if (state->active_tune == state->tune) {
            watch_set_indicator(WATCH_INDICATOR_BELL);
            tune_number = 1;
            }
        else {
            watch_clear_indicator(WATCH_INDICATOR_BELL);
        }
    }
    else if (state->tune == 2) {
        watch_display_string("Tn 3NNARIO", 0);
        if (state->active_tune == state->tune){
            watch_set_indicator(WATCH_INDICATOR_BELL);
            tune_number = 2;
            }
        else {
            watch_clear_indicator(WATCH_INDICATOR_BELL);
        }
    }   
    else if (state->tune == 3) {
        watch_display_string("Tn 4H1MM  ", 0);
        if (state->active_tune == state->tune){
            watch_set_indicator(WATCH_INDICATOR_BELL);
            tune_number = 3;
            }
        else {
            watch_clear_indicator(WATCH_INDICATOR_BELL);
        }
    }
    else if (state->tune == 4) {
        watch_display_string("Tn 51TENPO", 0);
        if (state->active_tune == state->tune){
            watch_set_indicator(WATCH_INDICATOR_BELL);
            tune_number = 4;
            }
        else {
            watch_clear_indicator(WATCH_INDICATOR_BELL);
        }
    }
    else if (state->tune == 5) {
        watch_display_string("Tn 6GRNdCL", 0);
        if (state->active_tune == state->tune){
            watch_set_indicator(WATCH_INDICATOR_BELL);
            tune_number = 5;
            }
        else {
            watch_clear_indicator(WATCH_INDICATOR_BELL);
        }
    }
}

bool hourly_tune_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    hourly_tune_state_t *state = (hourly_tune_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show your initial UI here.
            _hourly_tune_face_update_lcd(state);
            break;
        case EVENT_TICK:
            // if (state->active) {
            // }
            // If needed, update your display here.
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            if (!state->active) {
                state->tune = (state->tune + 1) % 6;
                _hourly_tune_face_update_lcd(state);
            }
            if (state->active) {
                state->active = false;
                watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
                watch_clear_pixel(2,4);
                state->tune = (state->tune + 1) % 6;
                _hourly_tune_face_update_lcd(state);
            }
            break;
        case EVENT_LIGHT_BUTTON_UP:
            // You can use the Light button for your own purposes. Note that by default, Movement will also
            // illuminate the LED in response to EVENT_LIGHT_BUTTON_DOWN; to suppress that behavior, add an
            // empty case for EVENT_LIGHT_BUTTON_DOWN.
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (!state->active) {
                state->active_tune = state->tune;
                _hourly_tune_face_update_lcd(state);
            }
            else {
                state->active_tune = state->tune;
                watch_set_indicator(WATCH_INDICATOR_BELL);
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            if (!state->active) {
                state->active = true;
                watch_set_indicator(WATCH_INDICATOR_SIGNAL);
                if (state->tune == 0) {
                    watch_display_string("Tn 1    dd", 0);
                    watch_set_pixel(2,4);
                    SIGNAL_TUNE_DEFAULT();

                }
                else if (state->tune == 1) {
                    watch_display_string("Tn 2    dd", 0);
                    watch_set_pixel(2,4);
                    SIGNAL_TUNE_ZELDA_SECRET();
                }
                else if (state->tune == 2) {
                    watch_display_string("Tn 3    dd", 0);
                    watch_set_pixel(2,4);
                    SIGNAL_TUNE_MARIO_THEME();
                }
                else if (state->tune == 3) {
                    watch_display_string("Tn 4    dd", 0);
                    watch_set_pixel(2,4);
                    SIGNAL_TUNE_KIM_POSSIBLE();
                }
                else if (state->tune == 4) {
                    watch_display_string("Tn 5    dd", 0);
                    watch_set_pixel(2,4);
                    SIGNAL_TUNE_POKEMON_ITEM();
                }
                else if (state->tune == 5) {
                    watch_display_string("Tn 6    dd", 0);
                    watch_set_pixel(2,4);
                    SIGNAL_TUNE_WINCHESTER();
                }
            } else {
                state->active = false;
                watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
                watch_clear_pixel(2,4);
                _hourly_tune_face_update_lcd(state);
            }
            break;
        case EVENT_MODE_BUTTON_UP:
            state->tune = 0;
            movement_move_to_next_face();
            break;
        case EVENT_MODE_LONG_PRESS:
            state->tune = 0;
            movement_move_to_face(0);
            break;
        case EVENT_TIMEOUT:
            // Your watch face will receive this event after a period of inactivity. If it makes sense to resign,
            // you may uncomment this line to move back to the first watch face in the list:
            // movement_move_to_face(0);
            if (!state->active) {
                state->tune = 0;
                movement_move_to_face(0);
            }
            else {
                state->tune = 0;
                movement_move_to_face(0);
            }
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            // If you did not resign in EVENT_TIMEOUT, you can use this event to update the display once a minute.
            // Avoid displaying fast-updating values like seconds, since the display won't update again for 60 seconds.
            // You should also consider starting the tick animation, to show the wearer that this is sleep mode:
            // watch_start_tick_animation(500);
            break;
        default:
            // Movement's default loop handler will step in for any cases you don't handle above:
            // * EVENT_LIGHT_BUTTON_DOWN lights the LED
            // * EVENT_MODE_BUTTON_UP moves to the next watch face in the list
            // * EVENT_MODE_LONG_PRESS returns to the first watch face (or skips to the secondary watch face, if configured)
            // You can override any of these behaviors by adding a case for these events to this switch statement.
            return movement_default_loop_handler(event, settings);
    }

    // return true if the watch can enter standby mode. Generally speaking, you should always return true.
    return true;
}

void hourly_tune_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    // handle any cleanup before your watch face goes off-screen.
}

