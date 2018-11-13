// Copyright (c) Shinya Ishikawa. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full
// license information.

#ifndef MYEYE_H_
#define MYEYE_H_

#include <utility/In_eSPI.h>
#include "DrawContext.h"
#include "Drawable.h"

namespace m5avatar {

class myEye final : public Drawable {
 private:
  uint16_t r;
  bool isLeft;

 public:
  // constructor
  myEye() = delete;
  myEye(uint16_t x, uint16_t y, uint16_t r, bool isLeft);  // deprecated
  myEye(uint16_t r, bool isLeft);
  ~myEye() = default;
  myEye(const myEye &other) = default;
  myEye &operator=(const myEye &other) = default;
  void draw(TFT_eSPI *spi, BoundingRect rect,
            DrawContext *drawContext) override;
  // void draw(TFT_eSPI *spi, DrawContext *drawContext) override; // deprecated
};

}  // namespace m5avatar

#endif  // MYEYE_H_
