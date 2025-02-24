/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:52:32 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/24 15:54:33 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

    #include <iostream>
    typedef unsigned long uintptr_t;

    struct Data
    {
        std::string nome;
        int idade;
    };


    class Serializer
    {
        private:
             Serializer();
             ~Serializer();
             Serializer (const Serializer &src);
             Serializer &operator=(const Serializer &src);
        public:
            static uintptr_t serialize(Data* ptr);
            static Data* deserialize(uintptr_t raw);
    };

#endif
