#ifndef _KEY_PAD_INTERFACE_H_
#define _KEY_PAD_INTERFACE_H_
//
#define KEY_pad_port PORTA
#define KEY_pad_dirction_init 0x0f
#define KEY_pad_value_init 0xff
#define puuton_pressed 0

void KEY_PAD_VidInit(void);


u8 KEY_PAD_VidGitPresed(void);

u8 KEY_PAD_VidGitPresedcalc(void);
#endif
