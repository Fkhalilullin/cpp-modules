/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteressa <mteressa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:33:31 by mteressa          #+#    #+#             */
/*   Updated: 2021/07/10 14:47:12 by mteressa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>



class Fixed
{
    
public:

    Fixed(void);
    ~Fixed(void);
    Fixed(Fixed const &src);
    
    Fixed & operator=(Fixed const &rhs);
    
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    
private:

    int                 _value;
    static const int    _number_of_fractional_bits;

};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif