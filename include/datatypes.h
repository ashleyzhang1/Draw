#ifndef DATATYPES_H_
#define DATATYPES_H_

#include "misc.h"
#include "linkedlist.h"

// 给每一类图形编号
#define DATATYPE_SEGMENT 1
#define DATATYPE_RECTANGLE 2
#define DATATYPE_CIRCLE 3
#define DATATYPE_ELLIPSE 4
#define DATATYPE_TEXT 5

#define DATATYPE_TEXT_MAX_LENGTH 255    // 字符串最长长度限制

#define DATATYPE_RANGE_MIN 1
#define DATATYPE_RANGE_MAX 5

#define FINDRULE_VARIATION 10

struct Vertex {
    int x, y;
};
struct Vertex * makeVertex(int newx, int newy);
void destroyVertex(struct Vertex *vtx);

struct Segment {
    struct Vertex *leftPt, *rightPt;
};
struct Segment * makeSegment(struct Vertex *newLeftPt, struct Vertex *newRightPt);
bool findSegmentRule(const struct Vertex *cursorPt, const struct Segment *seg);
void destroySegment(struct Segment *seg);

struct Rectangle {
    struct Vertex *lowerLeftPt, *upperRightPt;
};
struct Rectangle * makeRectangle(struct Vertex *newLowerLeftPt, struct Vertex *newUpperRightPt);
bool findRectangleRule(const struct Vertex *cursorPt, const struct Rectangle *rec);
void destroyRectangle(struct Rectangle *rec);

struct Circle {
    struct Vertex *centerPt;
    int radius;
};
struct Circle * makeCircle(struct Vertex *newCenterPt, int newRadius);
bool findCircleRule(const struct Vertex *cursorPt, const struct Circle *cir);
void destoryCircle(struct Circle *cir);

struct Ellipse {
    struct Vertex *centerPt;
    int majorSemiAxis, minorSemiAxis;
};
struct Ellipse * makeEllipse(struct Vertex *newCenterPt, int newMajorSemiAxis, int newMinorSemiAxis);
bool findEllipseRule(const struct Vertex *cursorPt, const struct Ellipse *elp);
void destroyEllipse(struct Ellipse *elp);

struct Text {
    struct Rectangle *position;
    int fontWidth, fontHeight;
    char *content;
};
struct Text * makeText(struct Rectangle *newPosition, char *newContent, int newFontWidth, int newFontHeight);
bool findTextRule(const struct Vertex *cursorPt, const struct Text *txt);
void destroyText(struct Text *txt);

void destroyRule(struct NodeData *data);
bool findRule(const void *vCursorPt, const struct LinkedNode *node);

#endif
