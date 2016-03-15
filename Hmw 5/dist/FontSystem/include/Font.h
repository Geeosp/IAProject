#ifndef FONT_H
#define FONT_H

#include "AzulCore.h"
#include "Glyph.h"
#include <assert.h>
#include <map>

#include "rapidxml.h"
#include "rapidxml_iterators.h"
#include "rapidxml_print.h"
#include "rapidxml_utils.h"

class Font 
{
public:
	Font(Texture * _text, char * _metricsFile);
	~Font();


	Glyph * getGlyph(int key);
	Texture * getText();

	Model * getFontModel();
	ShaderObject * getFontShaderObject();

protected:
	Texture * text;
	char * metricsFile;
	int count;

	Model * pFontModel;
	ShaderObject *pFontShaderObj;

	// Glyph List
	std::map<int, Glyph *>  glyphs;


	void clear();
	void addGlyph(Glyph * glyph);
	void createGlyphs();
};

#endif