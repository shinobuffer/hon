
#pragma once

#include "hon_entity.h"

namespace hon {

class IOperation {
public:
  virtual ~IOperation() = default;

  virtual bool perform(HonEntity) = 0;
};

class CopyOperation : IOperation {
  virtual ~CopyOperation() override = default;
};

class MoveOperation : IOperation {
  virtual ~MoveOperation() override = default;
};

} // namespace hon
