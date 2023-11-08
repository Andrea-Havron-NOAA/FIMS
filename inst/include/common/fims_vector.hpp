#ifndef FIMS_VECTOR_HPP
#define FIMS_VECTOR_HPP

#include "../interface/interface.hpp"

namespace  fims {


/**
 * Wrapper class for std::vector types. If this file is compiled with -DTMB_MODEL,
 * conversion operators are defined for TMB vector types.
 */
template<typename Type>
class Vector{
    std::vector<Type> vec_m;
    
    /**
     * @brief friiend comparison operator.
     */
    template<typename T>
    friend bool operator==( const fims::Vector<T>& lhs,
                           const fims::Vector<T>& rhs );
public:
    //Member Types
    
    typedef typename std::vector<Type>::value_type value_type; /*!<Member type Type>*/
    typedef typename std::vector<Type>::allocator_type allocator_type; /*!<Allocator for type Type>*/
    typedef typename std::vector<Type>::size_type size_type; /*<!Size type>*/
    typedef typename std::vector<Type>::difference_type difference_type; /*!<Difference type>*/
    typedef typename std::vector<Type>::reference reference;/*!<Reference type &Type>*/
    typedef typename std::vector<Type>::const_reference const_reference; /*!<Constant eference type const &Type>*/
    typedef typename std::vector<Type>::pointer pointer; /*!<Pointer type Type*>*/
    typedef typename std::vector<Type>::const_pointer const_pointer; /*!<Constant ointer type const Type*>*/
    typedef typename std::vector<Type>::iterator iterator; /*!<Iterator>*/
    typedef typename std::vector<Type>::const_iterator const_iterator;/*!<Constant iterator>*/
    typedef typename std::vector<Type>::reverse_iterator reverse_iterator;/*!<Reverse iterator>*/
    typedef typename std::vector<Type>::const_reverse_iterator const_reverse_iterator; /*!<Constant reverse iterator>*/
    
    /**
     * Default constructor.
     */
    Vector(){
    }
    
    /**
     * @brief Constructs the container of size copies of elements with value value.
     */
    Vector(size_t size, const Type& value = Type()){
        this->vec_m.resize(size, value);
    }
    
    /**
     * @brief Copy constructor.
     */
    Vector(const Vector<Type>& other){
        this->vec_m.resize(other.size());
        for(int i =0; i < this->vec_m.size(); i++){
            this->vec_m[i] = other[i];
        }
    }
    
    /**
     * @brief Initialization constructor with std::vector type..
     */
    Vector(const std::vector<Type>& other){
        this->vec_m = other;
    }
    
#ifdef TMB_MODEL
    
    /**
     * @brief Initialization constructor with tmbutils::vector type..
     */
    Vector(const tmbutils::vector<Type>& other){
        this->vec_m.resize(other.size());
        for(size_t i =0; i < this->vec_m.size(); i++){
            this->vec_m[i] = other[i];
        }
    }
    
    
#endif
    
    
    /**
     * @brief Returns a reference to the element at specified location pos. No bounds checking is performed.
     */
    inline Type& operator[](size_t pos){
        return this->vec_m[pos];
    }
    
    /**
     * @brief Returns a constant  reference to the element at specified location pos. No bounds checking is performed.
     */
    inline const Type& operator[](size_t n) const{
        return this->vec_m[n];
    }
    
    
    /**
     * @brief Returns a reference to the element at specified location pos. Bounds checking is performed.
     */
    inline Type& at(size_t n) {
        return this->vec_m.at(n);
    }
    
    /**
     * @brief Returns a constant reference to the element at specified location pos. Bounds checking is performed.
     */
    inline const Type& at(size_t n) const{
        return this->vec_m.at(n);
    }
    
    /**
     * @brief  Returns a reference to the first element in the container.
     */
    reference front() {
        return this->vec_m.front();
    }
    
    /**
     * @brief  Returns a constant reference to the first element in the container.
     */
    const_reference front() const {
        return this->vec_m.front();
    }
    
    /**
     * @brief  Returns a reference to the last element in the container.
     */
    reference back() {
        return this->vec_m.back();
    }
    
    
    /**
     * @brief  Returns a constant reference to the last element in the container.
     */
    const_reference back() const {
        return this->vec_m.back();
    }
    
    
    /**
     * @brief Returns a pointer to the underlying data array.
     */
    pointer data() {
        return this->vec_m.data();
    }
    
    
    /**
     * @brief Returns a constant pointer to the underlying data array.
     */
    const_pointer data() const {
        return this->vec_m.data();
    }
    
    //iterators
    
    
    /**
     * @brief Returns an iterator to the first element of the vector.
     */
    iterator begin() {
        return this->vec_m.begin();
    }
    
    /**
     * @brief Returns an iterator to the element following the last element of the vector.
     */
    iterator end() {
        return this->vec_m.end();
    }
    
    
    /**
     * @brief Returns an constant iterator to the first element of the vector.
     */
    const_iterator begin() const {
        return this->vec_m.begin();
    }
    
    /**
     * @brief Returns an const iterator to the element following the last element of the vector.
     */
    const_iterator end() const {
        return this->vec_m.end();
    }
    
    /**
     * @brief Returns a reverse iterator to the first element of the reversed vector. It corresponds to the last element of the non-reversed vector.
     */
    reverse_iterator rbegin() {
        return this->vec_m.rbegin();
    }
    
    /**
     * @brief Returns a reverse iterator to the element following the last element of the reversed vector. It corresponds to the element preceding the first element of the non-reversed vector.
     */
    reverse_iterator rend() {
        return this->vec_m.rend();
    }
    
    
    /**
     * @brief Returns a constant reverse iterator to the first element of the reversed vector. It corresponds to the last element of the non-reversed vector.
     */
    const_reverse_iterator rbegin() const {
        return this->vec_m.rbegin();
    }
    
    
    /**
     * @brief Returns a constant reverse iterator to the element following the last element of the reversed vector. It corresponds to the element preceding the first element of the non-reversed vector.
     */
    const_reverse_iterator rend() const {
        return this->vec_m.rend();
    }
    
    //capacity
    
    
    /**
     * @brief Checks whether the container is empty.
     */
    bool empty() {
        return this->vec_m.empty();
    }
    
    /**
     * @brief Returns the number of elements.
     */
    size_type size() const {
        return this->vec_m.size();
    }
    
    /**
     * @brief Returns the maximum possible number of elements.
     */
    size_type max_size() const {
        return this->vec_m.max_size();
    }
    
    /**
     * @brief Reserves storage.
     */
    void reserve(size_type cap) {
        this->vec_m.reserve(cap);
    }
    
    
    /**
     * @brief Returns the number of elements that can be held in currently allocated storage.
     */
    size_type capacity() {
        return this->vec_m.capacity();
    }
    
    /**
     *  @brief Reduces memory usage by freeing unused memory.
     */
    void shrink_to_fit() {
        this->vec_m.shrink_to_fit();
    }
    
    //modifiers
    
    /**
     * @brief Clears the contents.
     */
    void clear() {
        this->vec_m.clear();
    }
    
    
    /**
     * @brief Inserts value before pos.
     */
    iterator insert(const_iterator pos, const Type& value) {
        return this->vec_m.insert(pos, value);
    }
    
    /**
     * @brief Inserts count copies of the value before pos.
     */
    iterator insert(const_iterator pos, size_type count, const Type& value) {
        return this->vec_m.insert(pos, count, value);
    }
    
    /**
     * @brief Inserts elements from range [first, last) before pos.
     */
    template< class InputIt >
    iterator insert(const_iterator pos, InputIt first, InputIt last) {
        return this->vec_m.insert(pos, first, last);
    }
    
    /**
     * @brief Inserts elements from initializer list ilist before pos.
     */
    
    iterator insert(const_iterator pos, std::initializer_list<Type> ilist) {
        return this->vec_m.insert(pos, ilist);
    }
    
    
    /**
     * @brief Constructs element in-place.
     */
    template< class... Args >
    iterator emplace(const_iterator pos, Args&&... args) {
        return this->vec_m.emplace(pos, std::forward<Args>(args)...);
    }
    
    
    /**
     * @brief Removes the element at pos.
     */
    iterator erase(iterator pos) {
        return this->vec_m.erase(pos);
    }
    
    /**
     * @brief Removes the elements in the range [first, last).
     */
    iterator erase(iterator first, iterator last) {
        return this->vec_m.erase(first, last);
    }
    
    
    /**
     * @brief Adds an element to the end.
     */
    void push_back(const Type&& value) {
        this->vec_m.push_back(value);
    }
    
    /**
     * @brief Constructs an element in-place at the end.
     */
    template< class... Args >
    void emplace_back(Args&&... args) {
        this->vec_m.emplace_back(std::forward<Args>(args)...);
    }
    
    /**
     * @brief Removes the last element.
     */
    void pop_back() {
        this->vec_m.pop_back();
    }
    
    
    /**
     * @brief Changes the number of elements stored.
     */
    void resize(size_t s) {
        this->vec_m.resize(s);
    }
    
    /**
     * @brief Swaps the contents.
     */
    void swap( Vector& other ){
        this->vec_m.swap(other.vec_m);
    }
    
    
    //conversion operatrors
    
    /**
     * @brief Converts this vector a std::vector<Type>
     */
    inline operator std::vector<Type>(){
        return this->vec_m;
    }
    
#ifdef TMB_MODEL
    
    /**
     * @brief Converts this vector a CppAd::vector<Type>
     */
    inline operator CppAD::vector<Type>() const{
        return this->get_cppad_vector();
    }
    
    
    /**
     * @brief Converts this vector a tmbutils::vector<Type>
     */
    inline operator tmbutils::vector<Type>()const{
        return this->get_tmb_vector();
    }
    
private:
    
    
    /**
     * @brief Converts this vector a CppAd::vector<Type>
     */
    CppAD::vector<Type> get_cppad_vector() const{
        CppAD::vector<Type> ret;
        ret.resize(this->vec_m.size());
        for(size_t i =0; i < this->vec_m.size(); i++){
            ret[i] = this->vec_m[i];
        }
        return ret;
    }
    
    
    /**
     * @brief Converts this vector a tmbutils::vector<Type>
     */
    tmbutils::vector<Type> get_tmb_vector() const{
        tmbutils::vector<Type> ret;
        ret.resize(this->vec_m.size());
        for(size_t i =0; i < this->vec_m.size(); i++){
            ret[i] = this->vec_m[i];
        }
        return ret;
    }
    
    
#endif
    
    
};// end fims::Vector class

/**
 * @brief Comparison operator.
 */
template< class T>
bool operator==( const fims::Vector<T>& lhs,
                const fims::Vector<T>& rhs ){
    return lhs.vec_m == rhs.vec_m;
}


} //end fims namespace

#endif
