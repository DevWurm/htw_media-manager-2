#ifndef HTW_MEDIA_MANAGER_2_OPTIONAL_H
#define HTW_MEDIA_MANAGER_2_OPTIONAL_H

#include <stdexcept>

template <class T>
class optional {
private:
    const T* ref;

public:
    optional() noexcept;
    optional(T& val);
    optional(optional<T>& op);
    ~optional();

    bool hasValue() const noexcept;
    const T& getValue() const;

    void setValue(const T& val);
    void removeValue();

    optional<T>& operator=(optional& op);
};

template <class T>
optional<T>::optional() noexcept {
    this->ref = nullptr;
}

template <class T>
optional<T>::optional(T& val) {
    this->ref = new T(val);
}

template <class T>
optional<T>::optional(optional<T>& op) {
   if(op.hasValue()) {
       this->ref = new T(op.getValue());
   } else {
       this->ref = nullptr;
   }
}

template <class T>
optional<T>::~optional() {
    if (this->hasValue()) {
        delete this->ref;
    }
}

template <class T>
bool optional<T>::hasValue() const noexcept {
    return (this->ref != nullptr);
}

template <class T>
const T& optional<T>::getValue() const {
    if(!this->hasValue()) {
        throw logic_error("No value present in optional");
    }

    return *(this->ref);
}

template <class T>
void optional<T>::setValue(const T& val) {
    if (this->hasValue()) {
        delete this->ref;
    }

    this->ref = new T(val);
}

template <class T>
void optional<T>::removeValue() {
    if(this->hasValue()) {
        delete this->ref;
    }
    this->ref = nullptr;
}

template <class T>
optional<T>& optional<T>::operator=(optional &op) {
    if (this->hasValue()) {
        delete this->ref;
    }

    if(op.hasValue()) {
        this->ref = new T(op.getValue());
    } else {
        this->ref = nullptr;
    }
}

#endif //HTW_MEDIA_MANAGER_2_OPTIONAL_H
