#ifndef INCLUDE_MODELS_OBJECT_H
#define INCLUDE_MODELS_OBJECT_H

#include "definitions/definitions.h"

namespace furgbol {
namespace models {
  template<typename T>
  std::string to_json(const T& x) {}
  class json_serializable_t {
  public:
    template<typename T>
    json_serializable_t(T x) : self_(std::make_shared<model<T>>(std::move(x))) {}
    friend std::string to_json(const json_serializable_t& x)
    { return x.self_->to_json_(); }
  private:
    struct concept_t {
      virtual ~concept_t() = default;
      virtual std::string to_json_() const = 0;
    };
    template<typename T>
    struct model final : concept_t {
      model(T x) : data_(std::move(x)) {}
      std::string to_json_() const override
      { return to_json(data_); }
      T data_;
    };
    sptr<const concept_t> self_;
  };

  // template<typename T>
  // void draw(const T& x, std::ostream& out) {
  //   out << x << " (int)" << std::endl;
  // }
  // class object_t {
  // public:
  //   template<typename T>
  //   object_t(T x) : self_(std::make_shared<model<T>>(std::move(x))) {}
  //   friend void draw(std::ostream& out, const object_t& x)
  //   { x.self_->draw_(out); }
  // private:
  //   struct concept_t {
  //     virtual ~concept_t() = default;
  //     virtual void draw_(std::ostream&) const = 0;
  //   };
  //   template<typename T>
  //   struct model final : concept_t {
  //     model(T x) : data_(std::move(x)) {}
  //     void draw_(std::ostream& out) const override
  //     { draw(data_, out); }
  //     T data_;
  //   };
  //   sptr<const concept_t> self_;
  // };
}
}

#endif