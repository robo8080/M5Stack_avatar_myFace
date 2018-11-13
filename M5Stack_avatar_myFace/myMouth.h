// Copyright (c) Shinya Ishikawa. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full
// license information.

#ifndef MYMOUTH_H_
#define MYMOUTH_H_

#include <utility/In_eSPI.h>
#include "BoundingRect.h"
#include "DrawContext.h"
#include "Drawable.h"

namespace m5avatar {
class myMouth final : public Drawable {
 private:
  uint16_t minWidth;
  uint16_t maxWidth;
  uint16_t minHeight;
  uint16_t maxHeight;

 public:
  // constructor
  myMouth() = delete;
  ~myMouth() = default;
  myMouth(const myMouth &other) = default;
  myMouth &operator=(const myMouth &other) = default;
  myMouth(uint16_t minWidth, uint16_t maxWidth, uint16_t minHeight,
        uint16_t maxHeight);
  void draw(TFT_eSPI *spi, BoundingRect rect,
            DrawContext *drawContext) override;
};

}  // namespace m5avatar

#endif  // MYMOUTH_H_
