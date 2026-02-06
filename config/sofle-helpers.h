/*╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮              ╭─────up──────╮               ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮ */
/*├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤              ├────down─────┤               ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ */
/*├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤              ├────left─────┤               ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ */
/*├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤              ├────right────┤               ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ */
/*├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────╮├─────tap─────┤ ╭─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┴─────────────╯ */
/*╰─────────────╯             ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯╰─────────────╯ ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯ */

#define BASE 0
#define NAV 1
#define MOUSE 2
#define MEDIA 3
#define NUM 4
#define SYM 5
#define FN 6

#define WINDOWS 0
#define MAC 7
#define LINUX 14
#define ANDROID 21

#define XXX &none

#define ARG_1(_1, ...) _1
#define ARG_2(_1, _2, ...) _2
#define ARG_3(_1, _2, _3, ...) _3
#define ARG_4(_1, _2, _3, _4, ...) _4
#define ARG_5(_1, _2, _3, _4, _5, ...) _5
#define JOY_UP(...)    ARG_1(__VA_ARGS__)
#define JOY_DOWN(...)  ARG_2(__VA_ARGS__)
#define JOY_LEFT(...)  ARG_3(__VA_ARGS__)
#define JOY_RIGHT(...) ARG_4(__VA_ARGS__)
#define JOY_TAP(...)   ARG_5(__VA_ARGS__)


#define EYELASH_BASE_LAYER(name, sensors, LT, RT, LM, RM, LB, RB, LH, RH, JOYSTICK...)                     \
    ZMK_LAYER(                                                                                             \
        name,                                                                                              \
        XXX &kp N1 &kp N2 &kp N3 &kp N4 &kp N5  JOY_UP(JOYSTICK)    &kp N6 &kp N7 &kp N8 &kp N9 &kp N0 XXX \
        XXX                LT                   JOY_DOWN(JOYSTICK)                       RT            XXX \
        XXX                LM                   JOY_LEFT(JOYSTICK)                       RM            XXX \
        XXX                LB                   JOY_RIGHT(JOYSTICK)                      RB            XXX \
        &kp C_MUTE XXX XXX LH                   JOY_TAP(JOYSTICK)                        RH XXX XXX,       \
        sensors)

#define CONCAT_(a, b) a##b
#define CONCAT(a, b) CONCAT_(a, b)

#define CONCAT3(a, b, c) CONCAT(CONCAT(a, b), c)
#define CONCAT4(a, b, c, d) CONCAT(CONCAT3(a, b, c), d)
#define CONCAT5(a, b, c, d, e) CONCAT(CONCAT4(a, b, c, d), e)

#define OS_LAYER_POS(os, layer, pos) CONCAT5(os, _, layer, _, pos)

#define EMPTY_ROW &none &none &none &none &none

#define MY_BASE_LT &kp Q         &kp W         &kp E         &kp R         &kp T  
#define MY_BASE_LM &hml LCMD A   &hml LALT S   &hml LCTRL D  &hml LSHFT F  &kp G 
#define MY_BASE_LB &kp Z         &kp X         &kp C         &kp V         &kp B
#define MY_BASE_LH &lt 3 ESC     &lt 1 TAB     &lt 2 SPACE 

#define MY_BASE_RT &kp Y         &kp U         &kp I         &kp O         &kp P
#define MY_BASE_RM &kp H         &hmr LSHFT J  &hmr LCTRL K  &hmr LALT L   &hmr LCMD SQT
#define MY_BASE_RB &kp N         &kp M         &kp COMMA     &kp DOT       &kp SLASH
#define MY_BASE_RH &lt 6 ENTER   &lt 4 BSPC    &lt 5 DEL

#define MY_NAV_LT  EMPTY_ROW
#define MY_NAV_LM  EMPTY_ROW
#define MY_NAV_LB  EMPTY_ROW
#define MY_NAV_LH  XXX XXX XXX

#define MY_NAV_RT  &kp K_REDO    &kp K_PASTE   &kp K_COPY    &kp K_CUT     &kp K_UNDO 
#define MY_NAV_RM  &kp LEFT      &kp DOWN      &kp UP        &kp RIGHT     &kp CAPS 
#define MY_NAV_RB  &kp HOME      &kp PG_DN     &kp PG_UP     &kp END       &kp INSERT
#define MY_NAV_RH  &kp ENTER     &kp BSPC      &kp DEL

#define MY_MOUSE_LT  EMPTY_ROW
#define MY_MOUSE_LM  EMPTY_ROW
#define MY_MOUSE_LB  EMPTY_ROW
#define MY_MOUSE_LH  XXX XXX XXX

#define MY_MOUSE_RT &kp K_REDO     &kp K_PASTE    &kp K_COPY   &kp K_CUT       &kp K_UNDO 
#define MY_MOUSE_RM &mmv MOVE_LEFT &mmv MOVE_DOWN &mmv MOVE_UP &mmv MOVE_RIGHT &none 
#define MY_MOUSE_RB &msc SCRL_LEFT &msc SCRL_DOWN &msc SCRL_UP &msc SCRL_RIGHT &none 
#define MY_MOUSE_RH &mkp LCLK      &mkp RCLK      &mkp MCLK

#define MY_MEDIA_LT  EMPTY_ROW
#define MY_MEDIA_LM  EMPTY_ROW
#define MY_MEDIA_LB  EMPTY_ROW
#define MY_MEDIA_LH  XXX XXX XXX

#define MY_MEDIA_RT EMPTY_ROW 
#define MY_MEDIA_RM &kp C_PREV    &kp C_VOLUME_DOWN &kp C_VOLUME_UP &kp C_NEXT    &none  
#define MY_MEDIA_RB &out OUT_TOG  &bt BT_SEL 0      &bt BT_SEL 1    &bt BT_SEL 2  &bt BT_SEL 3  &bt BT_SEL 4  
#define MY_MEDIA_RH &kp C_STOP    &kp C_PP          &kp C_MUTE 

#define MY_NUM_LT &kp LBKT    &kp N7     &kp N8        &kp N9        &kp RBKT  
#define MY_NUM_LM &kp SEMI    &kp N4     &kp N5        &kp N6        &kp EQUAL 
#define MY_NUM_LB &kp GRAVE   &kp N1     &kp N2        &kp N3        &kp BSLH
#define MY_NUM_LH                        &kp MINUS     &kp N0        &kp DOT 

#define MY_NUM_RT  EMPTY_ROW
#define MY_NUM_RM  EMPTY_ROW
#define MY_NUM_RB  EMPTY_ROW
#define MY_NUM_RH  XXX XXX XXX

#define MY_SYM_LT  &kp LBRC    &kp AMPS   &kp ASTRK     &kp LPAR      &kp RBRC 
#define MY_SYM_LM  &kp COLON   &kp DLLR   &kp PRCNT     &kp CARET     &kp PLUS
#define MY_SYM_LB  &kp TILDE   &kp EXCL   &kp AT        &kp POUND     &kp PIPE 
#define MY_SYM_LH                         &kp LPAR      &kp RPAR      &kp UNDER 

#define MY_SYM_RT  EMPTY_ROW
#define MY_SYM_RM  EMPTY_ROW
#define MY_SYM_RB  EMPTY_ROW
#define MY_SYM_RH  XXX XXX XXX

#define MY_FN_LT  &none       &kp F7      &kp F8        &kp F9        &kp F10 
#define MY_FN_LM  &none       &kp F4      &kp F5        &kp F6        &kp F11 
#define MY_FN_LB  &none       &kp F1      &kp F2        &kp F3        &kp F12
#define MY_FN_LH  XXX XXX XXX

#define MY_FN_RT  EMPTY_ROW
#define MY_FN_RM  EMPTY_ROW
#define MY_FN_RB  EMPTY_ROW
#define MY_FN_RH  XXX XXX XXX