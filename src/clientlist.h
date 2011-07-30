/** Copyright 2011 Thorsten Wißmann. All rights reserved.
 *
 * This software is licensed under the "Simplified BSD License".
 * See LICENSE for details */


#ifndef __CLIENTLIST_H_
#define __CLIENTLIST_H_

#include <X11/Xlib.h>
#include <X11/Xproto.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
#include <glib.h>


typedef struct HSClient {
    Window      window;
    XRectangle  last_size;
} HSClient;

void clientlist_init();
void clientlist_destroy();

void window_focus(Window window);

void reset_client_colors();

// adds a new client to list of managed client windows
void manage_client(Window win);
void unmanage_client(Window win);

void window_enforce_last_size(Window in);

// destroys a special client
void destroy_client(HSClient* client);

HSClient* get_client_from_window(Window window);

void window_resize(Window win, XRectangle rect);
int window_close_current();

// some globals
unsigned long g_window_border_active_color;
unsigned long g_window_border_normal_color;

#endif


