// It will initialize the tensor handle =t= with the address of
// a valid backend tensor of kind @FIELD_NAME@.
// =ndim= is the number of dimensions of the tensor, e.g. =t(a,b,c)=
// has 3 dimensions.
// =lengths= is an array with the size of every dimension.
void tensor_init_@FIELD_NAME@(tensor_h* t,
                    const size_t ndim,
                    const size_t* lengths)
