/*
    Beginning DirectX 11 Game Programming
    By Allen Sherrod and Wendy Jones

    Solid Green Color Shader
*/



cbuffer cbChangesPerFrame : register(b0)
{
	matrix mvp_;
};


Texture2D colorMap_ : register(t0);
SamplerState colorSampler_ : register(s0);


struct VS_Input
{
	float4 pos  : POSITION;
	float4 color : TEXCOORD0;
};

struct PS_Input
{
	float4 pos  : SV_POSITION;
	float4 color : TEXCOORD0;
};


PS_Input VS_Main(VS_Input vertex)
{
	PS_Input vsOut = (PS_Input)0;
	vsOut.pos = mul(vertex.pos, mvp_);
	vsOut.color = vertex.color;

	return vsOut;
}


float4 PS_Main(PS_Input frag) : SV_TARGET
{
	return frag.color;
}
