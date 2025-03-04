/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:58:54 by aluzingu          #+#    #+#             */
/*   Updated: 2025/03/04 20:08:23 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

    #include <iostream>
    #include <vector>
    #include <deque>
    #include <algorithm>
    #include <ctime>
    #include <chrono>


    void sortDeque(std::deque<int>& deq)
    {
        std::sort(deq.begin(), deq.end());
    }
    
    class PMergeMe
    {
        private:
            std::vector<int> cont_vector;
            std::deque<int> cont_deque;
            int ft_isnumber(char *str)
            {
                int i = 0;
                while (str[i])
                {
                    if(!std::isdigit(str[i]))
                        return (0);
                    i++;
                }
                return (1);
            }

            void merge(int numeros[], int left_size, int right_size, int arrayLeft[], int arrayRight[])
            {
                int i = 0;
                int i_letf = 0;
                int i_right = 0;

                while (i_letf < left_size && i_right < right_size)
                {
                    if (arrayLeft[i_letf] < arrayRight[i_right])
                        numeros[i] = arrayLeft[i_letf++];
                    else
                        numeros[i] = arrayRight[i_right++];
                    i++;
                }
                while (i_letf < left_size)
                {
                    numeros[i] = arrayLeft[i_letf++];
                    i++;
                }
                while (i_right < right_size)
                {
                    numeros[i] = arrayRight[i_right++];
                    i++;
                }
            }

            void merge_sort(int numeros[], int size)
            {
                if (size <= 1)
                    return ;
                int left_size = size/2;
                int right_size = size - left_size;
                int arrayLeft[left_size];
                int arrayRight[right_size];
                int i = 0;
                int r = 0;
                while (i < size)
                {
                    if (i < left_size)
                        arrayLeft[i] = numeros[i];
                    else
                        arrayRight[r++] = numeros[i];
                    i++;
                }
                merge_sort(arrayLeft, left_size);
                merge_sort(arrayRight, right_size);
                this->merge(numeros, left_size, right_size, arrayLeft, arrayRight);
            }

        

        public:
            PMergeMe( int argc, char **argv)
            {
                int i = 1;

                while (i < argc)
                {
                    if (!this->ft_isnumber(argv[i]))
                    {
                        this->cont_vector.clear();
                        this->cont_deque.clear();
                        std::cout << "Error" << std::endl;
                        exit(1);
                    }
                    int number = std::atoi(argv[i]);
                    if (number < 0)
                    {
                        this->cont_vector.clear();
                        this->cont_deque.clear();
                        std::cout << "Error" << std::endl;
                        exit(1);
                    }
                    this->cont_vector.push_back(number);
                    this->cont_deque.push_back(number);
                    i++;
                }
                std::cout << "Before: ";
                std::vector<int>::iterator it = this->cont_vector.begin();
                while (it != this->cont_vector.end())
                {
                    std::cout << *it << " ";
                    it++;
                }
                std::cout << std::endl;
                
                clock_t start_vector = clock();
                this->merge_sort(this->cont_vector.data(), this->cont_vector.size());
                clock_t end_vector = clock();

                clock_t start_deque = clock();
                std::sort(this->cont_deque.begin(), this->cont_deque.end());
                clock_t end_deque = clock();

                std::cout << "After: ";
                it = this->cont_vector.begin();
                while (it != this->cont_vector.end())
                {
                    std::cout << *it << " ";
                    it++;
                }
                std::cout << std::endl;

                std::cout << "Time to process a range of " << this->cont_deque.size() \
                << " elements with std::deque : " << (end_deque - start_deque) << " ticks" << std::endl;

                std::cout << "Time to process a range of " << this->cont_vector.size() \
                << " elements with std::vector : " << (end_vector - start_vector) << " ticks" << std::endl;

            }
    };

#endif