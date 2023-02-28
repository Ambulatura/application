#ifndef H_OS_GRAPHICS_H

void os_graphics_set_vertex_buffer_data(OSWindowHandle os_window_handle, void* vertices, u32 vertex_count);
void os_graphics_set_vertex_input_layouts(OSWindowHandle os_window_handle, const char** names, u32* offsets, u32* formats, u32 stride, u32 layout_count);
void os_graphics_clear(uptr graphics, f32 r, f32 g, f32 b, f32 a);
void os_graphics_draw(OSWindowHandle os_window_handle);

#define H_OS_GRAPHICS_H
#endif