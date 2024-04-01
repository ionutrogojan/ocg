# OCG - Open Computer Graphics

An Open Implementation of Bitmap(Raster) and Vector Graphics

## .OBMG - Open BitMap Graphics

A free and Open Source Bitmap(Raster) Image format

Header:
- 8 bytes : magic - OCG00 - 00 = version
- 4 bytes : width (in px)
- 4 bytes : height (in px)
- 1 bytes : bit-depth
- 1 bytes : color-type
- ? bytes : title, author, description, copyright, creation time, last modified time, comment

This project is meant to work off of the PNG standard and improve it

https://www.w3.org/TR/2003/REC-PNG-20031110/#11IHDR

Bit-depth:
- 16 bit + alpha : [TODO] grayscale or rgb (up to 65536 shade/color values)
- 32 bit + alpha : [TODO] rgb

- 1 bit :
	- SHADE ( 0, 1 )
	- INDEX ( up to 8 colors )
	- COLOR ( r=0|1, g=0|1, b=0|1 )

- 2 bit :
	- SHADE ( 0, 1, 2, 3 )
	- INDEX ( up to 64 colors )
	- COLOR ( r=0|1|2|3, g=0|1|2|3, b=0|1|2|3 )

- 4 bit :
	- SHADE ( 0, ..15 )
	- INDEX ( up to 4096 colors )
	- COLOR ( r=0|..15, g=0|..15, b=0|..15 )

- 8 bit :
	- SHADE ( 0, ..255 ) + ALPHA ( 0, ..255 )
	- INDEX ( up to 16,777,216 )
	- COLOR ( r=0|..255, g=0|..255, b=0|..255 ) + ( a=0|..255 )

## .OVG - Open Vector Graphics

A free and Open Source Vector Image format

TODO