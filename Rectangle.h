#pragma once

class CRectangle {
private:
    int width, height;

public:
    void setWidth(int _width);
    int getWidth() const;
    void setHeight(int _height);
    int getHeight() const;
    int area();
};

void CRectangle::setHeight(int _height) {
    height = _height;
}

int CRectangle::getHeight() const {
    return height;
}

void CRectangle::setWidth(int _width) {
    width = _width;
}

int CRectangle::getWidth() const {
    return width;
}

int CRectangle::area() {
    return width * height;
}
