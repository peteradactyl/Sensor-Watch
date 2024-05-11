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
#include "tune_select_face.h"

// TODO
// Set a default signal tune (or must it be 0?)
// Simplify files so that this pulls from movement_custom_signal_tunes.h

int tune_number = 0;


void tune_select_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(tune_select_face_state_t));
        memset(*context_ptr, 0, sizeof(tune_select_face_state_t));
    }
}

void tune_select_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    tune_select_face_state_t *state = (tune_select_face_state_t *)context;
    state->active = false;
    // state->active_tune = 2;
}

static void _tune_select_face_update_lcd(tune_select_face_state_t *state) {
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

bool tune_select_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    tune_select_face_state_t *state = (tune_select_face_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            _tune_select_face_update_lcd(state);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            if (!state->active) {
                state->tune = (state->tune + 1) % 6;
                _tune_select_face_update_lcd(state);
            }
            if (state->active) {
                state->active = false;
                watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
                watch_clear_pixel(2,4);
                state->tune = (state->tune + 1) % 6;
                _tune_select_face_update_lcd(state);
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
                _tune_select_face_update_lcd(state);
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (!state->active) {
                state->active_tune = state->tune;
                _tune_select_face_update_lcd(state);
            }
            else {
                state->active_tune = state->tune;
                watch_set_indicator(WATCH_INDICATOR_BELL);
            }
            break;
        case EVENT_TICK:
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
            if (!state->active) {
                state->tune = 0;
                movement_move_to_face(0);
            }
            else {
                state->tune = 0;
                movement_move_to_face(0);
            }
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }
    return true;
}

void tune_select_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    watch_set_led_off();
}