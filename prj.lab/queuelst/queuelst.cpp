#include "queuelst.hpp"

QueueLst::QueueLst(const QueueLst& rhs) {
    if (rhs.head_ != nullptr) {
        if (this != &rhs) {
            Node* newNode = new Node(rhs.head_->v);
            head_ = newNode;
            tail_ = newNode;
            Node* current = rhs.head_->next;
            while (current != nullptr) {
                Node* newNode = new Node(current->v);
                current = current->next;
                tail_->next = newNode;
                tail_ = newNode;
            }
        }
    }
    else {
        head_ = nullptr;
        tail_ = nullptr;
    }
}

QueueLst::QueueLst(QueueLst&& rhs) noexcept {
    std::swap(head_, rhs.head_);
    std::swap(tail_, rhs.tail_);
}

QueueLst& QueueLst::operator=(QueueLst&& rhs) noexcept {
    if (this != &rhs) {
        std::swap(head_, rhs.head_);
        std::swap(tail_, rhs.tail_);
    }
    return *this;
}

QueueLst::~QueueLst() {
    while (head_ != nullptr) {
        Node* delete_future = head_;
        head_ = head_->next;
        delete delete_future;
        delete_future = nullptr;
    }
    tail_ = nullptr;
}

QueueLst& QueueLst::operator=(const QueueLst& rhs) {
    if (rhs.head_ == nullptr) {
        head_ = nullptr;
        tail_ = nullptr;
    }
    else {
        if (this != &rhs) {
            Node* rhs_cur = rhs.head_;
            Node* cur = head_;
            if (cur == nullptr) {
                Node* newNode = new Node;
                cur = newNode;
                head_ = newNode;
                tail_ = newNode;
            }
            while (rhs_cur != nullptr) {
                if (cur == nullptr) {
                    Node* newNode = new Node;
                    cur = newNode;
                    tail_->next = newNode;
                    tail_ = newNode;
                }

                cur->v = rhs_cur->v;
                rhs_cur = rhs_cur->next;

                if (rhs_cur == nullptr) {
                    tail_ = cur;
                    tail_->next = nullptr;
                }
                cur = cur->next;
            }
            while (cur != nullptr) {
                Node* temp = cur;
                cur = cur->next;
                delete temp;
                temp = nullptr;
            }
        }
    }
    return *this;
}

void QueueLst::Push(const Complex& c) {
    Node* newNode = new Node(c);
    if (head_ == nullptr) {
        head_ = newNode;
        tail_ = newNode;
    }
    else {
        tail_->next = newNode;
        tail_ = newNode;
    }
}

void QueueLst::Pop() noexcept {
    if (head_ != nullptr) {
        Node* delete_future = head_;
        head_ = head_->next;
        delete delete_future;
        delete_future = nullptr;
    }
    if (head_ == nullptr) {
        tail_ = nullptr;
    }
}

bool QueueLst::IsEmpty() const noexcept {
    return (head_ == nullptr);
}

Complex& QueueLst::Top() & {
    if (head_ == nullptr) {
        throw std::logic_error("Stack is empty!\n");
    }
    else {
        return head_->v;
    }
}
const Complex& QueueLst::Top() const & {
    if (head_ == nullptr) {
        throw std::logic_error("Stack is empty!\n");
    }
    else {
        return head_->v;
    }
}

void QueueLst::Clear() noexcept {
    while (head_ != nullptr) {
        Node* delete_future = head_;
        head_ = head_->next;
        delete delete_future;
        delete_future = nullptr;
    }
    tail_ = nullptr;
}
