#include "./parquet_int96.h"

#include "parquet/stream_reader.h"
#include "arrow/util/decimal.h"

namespace parquet {

StreamReaderLegacy& StreamReaderLegacy::operator>>(std::chrono::nanoseconds& v)
{
  CheckColumn(Type::INT96, ConvertedType::NONE);
  parquet::Int96 tmp;
  Read<Int96Reader>(&tmp);
  v = std::chrono::nanoseconds{Int96GetNanoSeconds(tmp)};
  return *this;
}

StreamReaderLegacy& StreamReaderLegacy::operator>>(std::optional<std::chrono::nanoseconds>& v)
{
  CheckColumn(Type::INT96, ConvertedType::NONE);
  std::optional<parquet::Int96> tmp;
  ReadOptional<Int96Reader, parquet::Int96>(&tmp);
  if (tmp.has_value())
  {
    v.emplace(Int96GetNanoSeconds(tmp.value()));
  }
  else
  {
    v.reset();
  }
  
  return *this;
}

StreamReaderLegacy& StreamReaderLegacy::operator>>(::arrow::Decimal128& v)
{
  static_cast<StreamReader&>(*this) >> v;
  return *this;
}

StreamReaderLegacy& StreamReaderLegacy::operator>>(optional<::arrow::Decimal128>& v)
{
  static_cast<StreamReader&>(*this) >> v;
  return *this;
}

StreamReaderLegacy& operator>>(StreamReaderLegacy& os, EndRowType) {
  os.EndRow();
  return os;
}

}