
struct VS_Input {
    float2 pos : POS;
    float2 uv : TEX;
};

struct ShaderInOut {
    float4 pos : SV_POSITION;
    float2 uv : TEX;
};

Texture2D    mytexture : register(t0);
SamplerState mysampler : register(s0);

ShaderInOut vs_main(VS_Input input)
{
    ShaderInOut output;
    output.pos = float4(input.pos, 0.0f, 1.0f);
    output.uv = input.uv;
    return output;
}

float4 ps_main(ShaderInOut input) : SV_Target
{
    return mytexture.Sample(mysampler, input.uv);   
}
