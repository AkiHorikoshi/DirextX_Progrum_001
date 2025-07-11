/*==============================================================================

   2D描画用ピクセルシェーダー [shader_pixel_2d.hlsl]
														 Author : Youhei Sato
														 Date   : 2025/05/15
--------------------------------------------------------------------------------

==============================================================================*/

struct PS_IN
{
	float4 posH : SV_POSITION;
	float4 color : COLOR0;
};

float4 main(PS_IN pi) : SV_TARGET
{
    return pi.color;
}
