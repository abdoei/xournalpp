/*
 * Xournal++
 *
 * Paper background type
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <XournalType.h>

enum class PageTypeFormat {
	PLAIN,
	LINED,
	LINED_VLINE,
	STAVES,
	STAVES_VLINE,
	GRAPH,
	DOTTED,
	PDF,
	IMAGE,
	COPY
};

class PageType
{
public:
	PageType();
	explicit PageType(PageTypeFormat format);
	PageType(const PageType& other);
	~PageType();

private:
	XOJ_TYPE_ATTRIB;

public:
	/**
	 * Compare Operator
	 */
	bool operator ==(const PageType& other) const;

	/**
	 * PDF background
	 */
	bool isPdfPage();

	/**
	 * Image Background
	 */
	bool isImagePage();

	/**
	 * Special background
	 */
	bool isSpecial();

public:
	/**
	 * Base format
	 */
	PageTypeFormat format;

	/**
	 * Arguments for the format
	 */
	string config;
};
