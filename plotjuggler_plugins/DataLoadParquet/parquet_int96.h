#pragma once

#ifndef PARQUET_INT96_H
#define PARQUET_INT96_H

#include <chrono>
#include <optional>
#include "parquet/stream_reader.h"

namespace parquet {

class StreamReaderLegacy : public StreamReader {
 public:

  StreamReaderLegacy() = default;

  explicit StreamReaderLegacy(std::unique_ptr<ParquetFileReader> reader) : StreamReader(std::move(reader)) {}

  ~StreamReaderLegacy() = default;

  // Moving is possible.
  StreamReaderLegacy(StreamReaderLegacy&&) = default;
  StreamReaderLegacy& operator=(StreamReaderLegacy&&) = default;

  // Copying is not allowed.
  StreamReaderLegacy(const StreamReaderLegacy&) = delete;
  StreamReaderLegacy& operator=(const StreamReaderLegacy&) = delete;

  StreamReaderLegacy& operator>>(std::chrono::nanoseconds& v);
  StreamReaderLegacy& operator>>(std::optional<std::chrono::nanoseconds>& v);

  StreamReaderLegacy& operator>>(bool& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(int8_t& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(uint8_t& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(int16_t& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(uint16_t& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(int32_t& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(uint32_t& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(int64_t& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(uint64_t& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(std::chrono::milliseconds& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(std::chrono::microseconds& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(float& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(double& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(char& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  template <int N>
  StreamReaderLegacy& operator>>(char (&v)[N]) { static_cast<StreamReader&>(*this) >> v; return *this; }

  template <std::size_t N>
  StreamReaderLegacy& operator>>(std::array<char, N>& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(std::string& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(::arrow::Decimal128& v);

  // Input operators for optional fields.

  StreamReaderLegacy& operator>>(optional<bool>& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(optional<int8_t>& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(optional<uint8_t>& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(optional<int16_t>& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(optional<uint16_t>& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(optional<int32_t>& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(optional<uint32_t>& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(optional<int64_t>& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(optional<uint64_t>& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(optional<float>& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(optional<double>& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(optional<std::chrono::milliseconds>& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(optional<std::chrono::microseconds>& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(optional<char>& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(optional<std::string>& v) { static_cast<StreamReader&>(*this) >> v; return *this; }

  StreamReaderLegacy& operator>>(optional<::arrow::Decimal128>& v);

  template <std::size_t N>
  StreamReaderLegacy& operator>>(optional<std::array<char, N>>& v) { static_cast<StreamReader&>(*this) >> v; return *this; }
};
  
StreamReaderLegacy& operator>>(StreamReaderLegacy&, EndRowType);

}

#endif
