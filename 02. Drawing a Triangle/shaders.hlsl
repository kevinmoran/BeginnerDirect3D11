
struct VertexInput
{
    float2 pos : POS;
    float4 color : COL;
};

struct ShaderInOut
{
    float4 position : SV_POSITION;
    float4 color : COL;
};

ShaderInOut vs_main(VertexInput input)
{
    ShaderInOut output;
    output.position = float4(input.pos, 0.0f, 1.0f);
    output.color = input.color;    

    return output;
}

float4 ps_main(ShaderInOut input) : SV_TARGET
{
    return input.color;   
}
