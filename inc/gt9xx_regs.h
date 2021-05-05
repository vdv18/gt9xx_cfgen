#ifndef __GT9XX_REGS_H__
#define __GT9XX_REGS_H__

#define GT9XX_REG_CFG_BASE           0x8047
#define GT9XX_REG_CONFIG_VERSION     0x8047
#define GT9XX_REG_X_OUTPUT_MAX_L     0x8048
#define GT9XX_REG_X_OUTPUT_MAX_H     0x8049
#define GT9XX_REG_Y_OUTPUT_MAX_L     0x804A
#define GT9XX_REG_Y_OUTPUT_MAX_H     0x804B
#define GT9XX_REG_TOUCH_NUMBER       0x804C
#define GT9XX_REG_MODULE_SWITCH1     0x804D
#define GT9XX_REG_MODULE_SWITCH2     0x804E
#define GT9XX_REG_SNAKE_COUNT        0x804F
#define GT9XX_REG_FILTER             0x8050
#define GT9XX_REG_LARGE_TOUCH        0x8051
#define GT9XX_REG_NOISE_REDUCTION    0x8052
#define GT9XX_REG_SCREEN_TOUCH_LEVEL 0x8053
#define GT9XX_REG_SCREEN_LEAVE_LEVEL 0x8054
#define GT9XX_REG_LOW_POWER_CONTROL  0x8055
#define GT9XX_REG_REFRASHE_RATE      0x8056
#define GT9XX_REG_X_THRESHOLD        0x8057
#define GT9XX_REG_Y_THRESHOLD        0x8058
#define GT9XX_REG_X_SPEED_LIMIT      0x8059
#define GT9XX_REG_Y_SPEED_LIMIT      0x805A
#define GT9XX_REG_SPACE_TB           0x805B
#define GT9XX_REG_SPACE_LR           0x805C
#define GT9XX_REG_MINI_FILTER        0x805D
#define GT9XX_REG_STRETCH_R0         0x805E
#define GT9XX_REG_STRETCH_R1         0x805F
#define GT9XX_REG_STRETCH_R2         0x8060
#define GT9XX_REG_STRETCH_RM         0x8061
//#define GT9XX_REG_ 0x8062
//#define GT9XX_REG_ 0x8063
//#define GT9XX_REG_ 0x8064
//#define GT9XX_REG_ 0x8065
//#define GT9XX_REG_ 0x8066
//#define GT9XX_REG_ 0x8067
//#define GT9XX_REG_ 0x8068
//#define GT9XX_REG_ 0x8069
//#define GT9XX_REG_ 0x806A
#define GT9XX_REG_PANNEL_TX_GAIN    0x806B
#define GT9XX_REG_PANNEL_RX_GAIN    0x806C
//#define GT9XX_REG_ 0x806D
//#define GT9XX_REG_ 0x806E
//#define GT9XX_REG_ 0x806F
//#define GT9XX_REG_ 0x8070
//#define GT9XX_REG_ 0x8071
//#define GT9XX_REG_ 0x8072
//#define GT9XX_REG_ 0x8073
//#define GT9XX_REG_ 0x8074
//#define GT9XX_REG_ 0x8075
//#define GT9XX_REG_ 0x8076
//#define GT9XX_REG_ 0x8077
//#define GT9XX_REG_ 0x8078
//#define GT9XX_REG_ 0x8079
//#define GT9XX_REG_ 0x807A
//#define GT9XX_REG_ 0x807B
//#define GT9XX_REG_ 0x807C
//#define GT9XX_REG_ 0x807D
//#define GT9XX_REG_ 0x807E
//#define GT9XX_REG_ 0x807F
//#define GT9XX_REG_ 0x8080
//#define GT9XX_REG_ 0x8081
//#define GT9XX_REG_ 0x8082
//#define GT9XX_REG_ 0x8083
//#define GT9XX_REG_ 0x8084
//#define GT9XX_REG_ 0x8085
//#define GT9XX_REG_ 0x8086
//#define GT9XX_REG_ 0x8087
//#define GT9XX_REG_ 0x8088
//#define GT9XX_REG_ 0x8089
//#define GT9XX_REG_ 0x808A
//#define GT9XX_REG_ 0x808B
//#define GT9XX_REG_ 0x808C
//#define GT9XX_REG_ 0x808D
//#define GT9XX_REG_ 0x808E
//#define GT9XX_REG_ 0x808F
//#define GT9XX_REG_ 0x8090
//#define GT9XX_REG_ 0x8091
//#define GT9XX_REG_ 0x8092
//#define GT9XX_REG_ 0x8093
//#define GT9XX_REG_ 0x8094
//#define GT9XX_REG_ 0x8095
//#define GT9XX_REG_ 0x8096
//#define GT9XX_REG_ 0x8097
//#define GT9XX_REG_ 0x8098
//#define GT9XX_REG_ 0x8099
//#define GT9XX_REG_ 0x809A
//#define GT9XX_REG_ 0x809B
//#define GT9XX_REG_ 0x809C
//#define GT9XX_REG_ 0x809D
//#define GT9XX_REG_ 0x809E
//#define GT9XX_REG_ 0x809F
//#define GT9XX_REG_ 0x80A0
//#define GT9XX_REG_ 0x80A1
//#define GT9XX_REG_ 0x80A2
//#define GT9XX_REG_ 0x80A3
//#define GT9XX_REG_ 0x80A4
//#define GT9XX_REG_ 0x80A5
//#define GT9XX_REG_ 0x80A6
//#define GT9XX_REG_ 0x80A7
//#define GT9XX_REG_ 0x80A8
//#define GT9XX_REG_ 0x80A9
//#define GT9XX_REG_ 0x80AA
//#define GT9XX_REG_ 0x80AB
//#define GT9XX_REG_ 0x80AC
//#define GT9XX_REG_ 0x80AD
//#define GT9XX_REG_ 0x80AE
//#define GT9XX_REG_ 0x80AF
//#define GT9XX_REG_ 0x80B0
//#define GT9XX_REG_ 0x80B1
//#define GT9XX_REG_ 0x80B2
//#define GT9XX_REG_ 0x80B3
//#define GT9XX_REG_ 0x80B4
//#define GT9XX_REG_ 0x80B5
//#define GT9XX_REG_ 0x80B6
//#define GT9XX_REG_ 0x80B7
//#define GT9XX_REG_ 0x80B8
//#define GT9XX_REG_ 0x80B9
//#define GT9XX_REG_ 0x80BA
//#define GT9XX_REG_ 0x80BB
//#define GT9XX_REG_ 0x80BC
//#define GT9XX_REG_ 0x80BD
//#define GT9XX_REG_ 0x80BE
//#define GT9XX_REG_ 0x80BF
//#define GT9XX_REG_ 0x80C0
//#define GT9XX_REG_ 0x80C1
//#define GT9XX_REG_ 0x80C2
//#define GT9XX_REG_ 0x80C3
//#define GT9XX_REG_ 0x80C4
//#define GT9XX_REG_ 0x80C5
//#define GT9XX_REG_ 0x80C6
//#define GT9XX_REG_ 0x80C7
//#define GT9XX_REG_ 0x80C8
//#define GT9XX_REG_ 0x80C9
//#define GT9XX_REG_ 0x80CA
//#define GT9XX_REG_ 0x80CB
//#define GT9XX_REG_ 0x80CC
//#define GT9XX_REG_ 0x80CD
//#define GT9XX_REG_ 0x80CE
//#define GT9XX_REG_ 0x80CF
//#define GT9XX_REG_ 0x80E0
//#define GT9XX_REG_ 0x80E1
//#define GT9XX_REG_ 0x80E2
//#define GT9XX_REG_ 0x80E3
//#define GT9XX_REG_ 0x80E4
//#define GT9XX_REG_ 0x80E5
//#define GT9XX_REG_ 0x80E6
//#define GT9XX_REG_ 0x80E7
//#define GT9XX_REG_ 0x80E8
//#define GT9XX_REG_ 0x80E9
//#define GT9XX_REG_ 0x80EA
//#define GT9XX_REG_ 0x80EB
//#define GT9XX_REG_ 0x80EC
//#define GT9XX_REG_ 0x80ED
//#define GT9XX_REG_ 0x80EE
//#define GT9XX_REG_ 0x80EF
//#define GT9XX_REG_ 0x80F0
//#define GT9XX_REG_ 0x80F1
//#define GT9XX_REG_ 0x80F2
//#define GT9XX_REG_ 0x80F3
//#define GT9XX_REG_ 0x80F4
//#define GT9XX_REG_ 0x80F5
//#define GT9XX_REG_ 0x80F6
//#define GT9XX_REG_ 0x80F7
//#define GT9XX_REG_ 0x80F8
//#define GT9XX_REG_ 0x80F9
//#define GT9XX_REG_ 0x80FA
//#define GT9XX_REG_ 0x80FB
//#define GT9XX_REG_ 0x80FC
//#define GT9XX_REG_ 0x80FD
//#define GT9XX_REG_ 0x80FE
//#define GT9XX_REG_ 0x80FF
//#define GT9XX_REG_ 0x8100

#endif//__GT9XX_REGS_H__