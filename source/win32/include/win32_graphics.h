#ifndef H_WIN32_GRAPHICS_H

uptr win32_graphics_init(uptr handle_pointer);
void win32_graphics_use_shader(uptr graphics_pointer, uptr shader_pointer);
void win32_graphics_use_input_layout(uptr graphics_pointer, uptr input_layout_pointer);
void win32_graphics_set_vertex_buffer_data(uptr graphics_pointer, const void* vertex_buffer_data, u32 vertex_buffer_size);
void win32_graphics_add_vertex_buffer_data(uptr graphics_pointer, const void* vertex_buffer_data, u32 vertex_buffer_size);
uptr win32_graphics_create_input_layout(const u8* vertex_shader_buffer, u32 vertex_shader_buffer_size,
                                        const char** names, const u32* offsets, const u32* formats, u32 stride, u32 layout_count);
uptr win32_graphics_create_texture_2D(uptr graphics_pointer, const u32* texture_buffer, i32 width, i32 height);
void win32_graphics_use_texture_2Ds(uptr graphics_pointer, uptr* texture_2Ds, u32 texture_count);
uptr win32_graphics_create_vertex_shader(const u8* shader_buffer, u32 shader_buffer_size);
uptr win32_graphics_create_pixel_shader(const u8* shader_buffer, u32 shader_buffer_size);
void win32_graphics_clear(uptr graphics_pointer, RGBA color);
void win32_graphics_draw_rectangle(uptr graphics_pointer, i32 x, i32 y, i32 width, i32 height, RGBA color);
void win32_graphics_draw_triangle(uptr graphics_pointer, V2 v1, V2 v2, V2 v3, RGBA color);
void win32_graphics_draw_circle_section(uptr graphics_pointer, i32 center_x, i32 center_y, f32 radius,
                                        f32 start_angle, f32 end_angle, i32 segments, RGBA color);
void win32_graphics_draw_circle(uptr graphics_pointer, i32 center_x, i32 center_y, f32 radius, RGBA color);
void win32_graphics_draw_pixel(uptr graphics_pointer, i32 x, i32 y, RGBA color);
void win32_graphics_draw(uptr graphics_pointer);

#define H_WIN32_GRAPHICS_H
#endif
