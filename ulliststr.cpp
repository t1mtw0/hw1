#include "ulliststr.h"
#include <cstddef>
#include <stdexcept>

ULListStr::ULListStr() {
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

ULListStr::~ULListStr() { clear(); }

bool ULListStr::empty() const { return size_ == 0; }

size_t ULListStr::size() const { return size_; }

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string &val) {
    if (empty()) {
        Item *item = new Item();
        item->val[item->last++] = val;
        head_ = tail_ = item;
        size_++;
        return;
    }
    if (tail_->first == 0 && tail_->last == ARRSIZE) {
        Item *item = new Item();
        item->val[item->last++] = val;
        tail_->next = item;
        item->prev = tail_;
        tail_ = item;
    } else {
        tail_->val[tail_->last++] = val;
    }
    size_++;
}

void ULListStr::pop_back() {
    if (empty())
        return;
    tail_->last--;
    if (tail_->last == tail_->first) {
        if (tail_->prev == NULL) {
            delete tail_;
            tail_ = head_ = NULL;
        } else {
            tail_ = tail_->prev;
            delete tail_->next;
            tail_->next = NULL;
        }
    }
    size_--;
}

void ULListStr::push_front(const std::string &val) {
    if (empty()) {
        Item *item = new Item();
        item->val[item->last++] = val;
        head_ = tail_ = item;
        size_++;
        return;
    }
    if (head_->first != 0) {
        head_->val[--head_->first] = val;
        size_++;
        return;
    }
    Item *item = new Item();
    item->first = item->last = ARRSIZE;
    item->val[--item->first] = val;
    head_->prev = item;
    item->next = head_;
    head_ = item;
    size_++;
}

void ULListStr::pop_front() {
    if (empty()) return;
    head_->first++;
    if (head_->first == head_->last) {
        if (head_->next == NULL) {
            delete head_;
            head_ = tail_ = NULL;
        } else {
            head_ = head_->next;
            delete head_->prev;
            head_->prev = NULL;
        }
    }
    size_--;
}

std::string const &ULListStr::back() const {
    if (empty()) return NULL;
    return tail_->val[tail_->last - 1];
}

std::string const &ULListStr::front() const {
    if (empty()) return NULL;
    return head_->val[head_->first];
}

void ULListStr::set(size_t loc, const std::string &val) {
    std::string *ptr = getValAtLoc(loc);
    if (ptr == NULL) {
        throw std::invalid_argument("Bad location");
    }
    *ptr = val;
}

std::string &ULListStr::get(size_t loc) {
    std::string *ptr = getValAtLoc(loc);
    if (ptr == NULL) {
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

std::string const &ULListStr::get(size_t loc) const {
    std::string *ptr = getValAtLoc(loc);
    if (ptr == NULL) {
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

void ULListStr::clear() {
    while (head_ != NULL) {
        Item *temp = head_->next;
        delete head_;
        head_ = temp;
    }
    tail_ = NULL;
    size_ = 0;
}

std::string *ULListStr::getValAtLoc(size_t loc) const {
    if (empty()) return NULL;
    if (loc >= size_) return NULL;
    Item *current = head_;
    size_t cur_loc = head_->first;
    for (int i = 0; i < loc; ++i) {
        if (cur_loc == current->last - 1) {
            cur_loc = -1;
            current = current->next;
        }
        cur_loc++;
    }
    return &current->val[cur_loc];
}
