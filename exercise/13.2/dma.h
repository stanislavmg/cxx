#ifndef DMA_H
#define DMA_H

#include <iostream>
#include <cstring>

class abcDMA
{
private:
	char *label;
	int rating;
public:
	abcDMA(const char *l = "null", int r = 0);
	abcDMA(const abcDMA &d);
	virtual ~abcDMA();
	abcDMA &operator=(const abcDMA &d);
	virtual void View() = 0;
	friend std::ostream &operator<<(std::ostream os, const abcDMA &d);
};

class lacksDMA : public abcDMA
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];
public:
	lacksDMA(const char *c = "blank", const char *l = "null", int r = 0);
	lacksDMA(const char *c, const abcDMA &ad);
	virtual void View();
	friend std::ostream &operator<<(std::ostream os, const lacksDMA &ld);
};

class hasDMA : public abcDMA
{
private:
	char *style;
public:
	hasDMA(const char *s = "none", const char *l = "null", int r = 0);
	hasDMA(const hasDMA *hd);
	~hasDMA();
	virtual void View();
	virtual hasDMA &operator=(const hasDMA &hd);
	friend std::ostream &operator<<(std::ostream os, const hasDMA &hd);
};

#endif