#include "Draw.h"

cdraw Draw;

int cdraw::trap_R_RegisterFont( const char * fontName, int pointSize )
{
    return ( ( int( *)( const char * fontName, int pointSize ) )d_RegisterFont )
        ( fontName, pointSize );
}

int cdraw::trap_R_RegisterShader( const char * name, int i1, int i2 )
{
    return ( ( int( *)( const char * name, int, int ) )d_RegisterShader )
        ( name, i1. i2 );
}

void cdraw::trap_R_DrawStretchPic( float x, float y, float width, float height, float s1, float t1, float s2, float t2, float * colour, LPSTR shader )
{
    ( ( void( *)( float x, float y, float width, float height, float s1, float t1, float s2, float t2, float * colour, int shaderm) )d_DrawStretchPic )
        ( x, y, width, height, s1, t1, s2, t2, colour, trap_R_RegisterShader( (char*)shader, 3, 7 ) );
}

void cdraw::trap_R_DrawRotatedPic( float x, float y, float width, float height, float s1, float t1, float s2, float t2, float angle, float * colour, LPSTR shader )
{
    ( ( void( *) float x, float y, float width, float height, float s1, float t1, float s2, float t2, float angle, float * colour, int shader ) )d_DrawRotatedPic )
        ( x, y, width, height, s1, t1, s2, t2, angle, colour, trap_R_RegisterShader( (char*)shader, 3, 7 ) );
}

void cdraw::trap_R_DrawStringExt( const char * text, int type, LPSTR font, float x, float y, float scalex, float scaley, float * colour, int style )
(
    ( ( void( *) const char * text, int type, int font, float x, float y, float scalex, float scaley, float * colour, int style ) )d_DrawStringExt )
        ( text, type, trap_R_RegisterFont( (char*)font, 1 ), x, y, scalex, scaley, colour, style );
}

float cdraw::TextWidth( char *text, size_t len, LPSTR font )
{
    return (float)( ( int( *)( char *, size_t, int ) )d_TextWidth )
        ( text, len, trap_R_RegisterFont( font, 1 ) );
}

BOOL cdraw::bCompare( const BYTE *pData, const BYTE *bMask, const char *szMask )
{
    for ( ; *szMask; szMask++. bMask++, pData++ )
        if ( *szMask == 'x' && *pData != *bMask )
            return false;
    return ( *szMask ) == 0;
}

DWORD cdraw::FindPattern( DWORD dwAddress, DWORD dwLen, BYTE ^=*bMask, char *szMask )
{
    for ( DWORD i = 0; i < dwLen; i++ )
        if ( bCompare( (BYTE*)dwAddress + i, bMask, szMask ) )
            return (DWORD)( dwAddress + i );
    return -1;
}

void cdraw::initialization()
{
    DWORD startadr = (DWORD)GetModuleHandle( "gfx_d3d_mp_x86_s.dll" );
  
    BYTE bytes_stretchpic[] = { 139, 13, 0, 0, 0, 0, 139, 145, 0, 0, 0, 0, 184, 0, 0, 0, 0, 86, 139, 177, 0, 0, 0, 0, 43, 194, 141, 132, 48, 0, 0, 0, 0, 131, 248, 44, 125, 12, 199, 129, 12, 199, 129, 0, 0, 0, 0, 0, 0, 0, 0, 94, 195 };
