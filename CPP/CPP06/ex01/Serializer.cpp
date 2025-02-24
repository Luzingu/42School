/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:52:43 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/24 15:55:27 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::~Serializer()
{
    
}

Serializer &Serializer::operator=(const Serializer &src)
{
    *this = src;
    return (*this);
}

Serializer::Serializer(const Serializer &src)
{
    (void) src;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast <uintptr_t> (ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast <Data *>(raw);
}
