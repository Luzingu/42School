/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:27:12 by aluzingu          #+#    #+#             */
/*   Updated: 2025/03/04 20:24:01 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

    #include <iostream>
    #include <cstdlib>
    #include <stack>
    
    class RPN
    {
        private:
            std::stack<int>numeros;
            
            bool is_signal(char c)
            {
                return (c == '+' || c == '-' || c == '*' || c == '/');
            }
            
            void check_expression(std::string expression)
            {
                size_t signals_len = 0;
                size_t numbers_len = 0;
                size_t i = 0;
                bool last_was_space = true;

                while (i < expression.length())
                {
                    if (!(expression[i] == ' ' || std::isdigit(expression[i]) || this->is_signal(expression[i])))
                    {
                        std::cout << "Invalid Caracter" << std::endl;
                        exit(1);
                    }
                    if(expression[i] != ' ')
                    {
                        if(!last_was_space)
                        {
                            std::cout << "Invalid Expression" << std::endl;
                            exit(1);
                        }
                        last_was_space = false;
                        if(this->is_signal(expression[i]))
                            signals_len++;
                        else
                            numbers_len++;
                    }
                    else
                        last_was_space = true;              
                    i++;
                }

                if((numbers_len - signals_len) != 1)
                {
                    std::cout << "Invalid Expression" << std::endl;
                    exit(1);
                }
            }

            int ft_calc(char signal, int num1, int num2)
            {
                if (signal == '+')
                    return (num2 + num1);
                else  if (signal == '-')
                    return (num2 - num1);
                else  if (signal == '*')
                    return (num2 * num1);
                else  if (signal == '/')
                    return (num2 / num1);
                return (0);
            }

        public:
            RPN (std::string expression)
            {
                this->check_expression(expression);
                size_t i = 0;
                while (i < expression.length())
                {
                    if(expression[i] != ' ')
                    {
                        if(this->is_signal(expression[i]))
                        {
                            if (this->numeros.size() <= 1)
                            {
                                std::cout << "Invalid Expression" << std::endl;
                                exit(1);
                            }
                            int num1 = this->numeros.top();
                            this->numeros.pop();
                            int num2 = this->numeros.top();
                            this->numeros.pop();
                            this->numeros.push(this->ft_calc(expression[i], num1, num2));
                            
                        }
                        else
                            this->numeros.push(expression[i] - 48);
                    }
                    i++;
                }
                std::cout << this->numeros.top() << std::endl;                
            }
    };
#endif
