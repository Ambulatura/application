// NOTE: These names must match D3D11_INPUT_ELEMENT_DESC array.
struct VS_INPUT
{
    float2 pos   : POSITION;
    float2 uv    : TEXCOORD;
    float4 color : COLOR;
};

// NOTE: These names do not matter, except SV_... ones.
struct PS_INPUT
{
    float4 pos   : SV_POSITION;
    float2 uv    : TEXCOORD;
    float4 color : COLOR;
};

// NOTE: b0 = constant buffer bound to slot 0.
cbuffer cbuffer0 : register(b0)
{
    float4 u_screen; // NOTE: x, y -> screen size
}

// NOTE: s0 = sampler bound to slot 0.
sampler sampler0 : register(s0);

// NOTE: t0 = shader resource bound to slot 0.
Texture2D<float4> texture0 : register(t0);

// NOTE: t1 = shader resource bound to slot 1.
Texture2D<float4> texture1 : register(t1);

PS_INPUT vs(VS_INPUT input)
{
    PS_INPUT output;
    output.pos = float4((2.0f * u_screen.xy * input.pos) - 1.0f, 0.0f, 1.0f);
    output.uv = input.uv;
    output.color = clamp(1.0f / 255.0f * input.color, 0.0f, 1.0f);
    return output;
}

float4 ps(PS_INPUT input) : SV_TARGET
{
    float4 tex = float4(1.0f, 1.0f, 1.0f, 1.0f);

    if (input.uv.x != -1.0f && input.uv.y != -1.0f)
    {
        tex = texture0.Sample(sampler0, input.uv);
    }

    return input.color * tex;
}
