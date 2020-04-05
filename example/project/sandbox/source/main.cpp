#include <string>
#include <vector>
#include <assert.h>
#include <FOSL/strong_type.hpp>

using namespace FOSL::strong_type;

using wrapped_int        = value_wrapper<            int >;
using wrapped_int_vector = value_wrapper<std::vector<int>>;

int main(void)
{
	wrapped_int i1{0}; i1 = 1;
	wrapped_int i2{0}; i2 = 2;
	wrapped_int i {0}; i  = 0;
	assert(i1 ==  1);
	assert(i2 !=  1);
	assert(1  == i1);
	assert(1  != i2);
	assert(i1 == i1);
	assert(i1 != i2);
	assert(i1 <  i2);
	assert(i2 >  i1);
	assert(i1 <= i2);
	assert(i2 >= i1);
	assert(i1 <= i1);
	assert(i1 >= i1);
	assert(i1 <   2);
	assert(i2 >   1);
	assert(i1 <=  2);
	assert(i2 >=  1);
	assert(i1 <=  1);
	assert(i1 >=  1);
	assert( 1 <  i2);
	assert( 2 >  i1);
	assert( 1 <= i2);
	assert( 2 >= i1);
	assert( 1 <= i1);
	assert( 1 >= i1);
	i = 0; assert(++i);
	i = 1; assert(i--);
	i = 1; assert(i++);
	i = 2; assert(--i);
	i = 0; i += 1; assert(i == 1);
	i = 2; i -= 1; assert(i == 1);
	i = 1; i *= 2; assert(i == 2);
	i = 2; i /= 2; assert(i == 1);
	assert(i2 + i1 == 3);
	assert(i2 - i1 == 1);
	assert(i2 * i1 == 2);
	assert(i2 / i1 == 2);

	wrapped_int_vector v{};
	v.push_back(1);
}
