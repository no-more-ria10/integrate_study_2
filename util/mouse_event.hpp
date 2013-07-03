/*
  マウスイベントの関数を用意
*/

#ifndef __MOUSE_EVENT_H__
#define __MOUSE_EVENT_H__

//移動量の計算。
double* get_rotate();

void motion_func(int x, int y);

void move_step(int button, int state, int x, int y);











#endif
