#include <>
#include <optional>

template <typename T>
std::optional<sizt_t> Find(const T &value, const T *arr, size_t size) {
  for (size_t i{0}; i < size; i++) {
    if (arr[i] == value) {
      return i; // Found it; return the index.
    }
  }
  return NOT_FOUND; // Failed to find it; return NOT_FOUND.
}