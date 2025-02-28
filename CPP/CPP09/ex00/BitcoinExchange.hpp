/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:13:34 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/28 16:06:15 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP
    #include <iostream>
    #include <fstream>
    #include <map>
    #include <cstring>
    #include <cstdlib>
    
    std::string trim(const std::string& str);
    void gate_date_value(const std::string &str, const std::string &separator, std::string &date, float &value);
    bool valid_date(std::string data);

    class BTC
    {
        private:
            std::map<std::string, float> data;
            int analize;
            
            void    read_data_file()
            {
                std::ifstream data_file("data.csv");
                if(!data_file)
                {
                    std::cout << "Error: could not open file." << std::endl;
                    return ;
                }
                std::string date;
                float value;
                std::string linha;
                while(std::getline(data_file, linha))
                {
                    gate_date_value(linha, ",", date, value);
                    this->data[date] = value;
                }
                data_file.close();
            }

            std::map<std::string, float>::iterator get_exchange(std::string date)
            {
                std::map<std::string, float>::iterator it = this->data.lower_bound(date);
                if(it == this->data.end())
                    it--;
                return (it);
            }
            
            void    read_input_file(std::string file)
            {
                std::ifstream input_file(file.c_str());
                if (!input_file)
                {
                    std::cout << "Error: could not open file." << std::endl;
                    return ;
                }
                std::string linha;
                std::string date;
                float value;
                while(std::getline(input_file, linha))
                {
                    this->analize = 0;
                    gate_date_value(linha, "|", date, value);
                    if(!valid_date(date))
                        std::cout << "Error: bad input => " << date << std::endl;
                    else if (value < 0)
                        std::cout << "Error: not a positive number." << std::endl;
                    else if (value > 1000)
                        std::cout << "Error: too large a number." << std::endl;
                    else
                    {
                        std::map<std::string, float>::iterator it = this->get_exchange(date);
                        std::cout << date << " => " << (it->second * value) << std::endl;
                    }
                }
                input_file.close();
            }
            
        public:
            BTC(std::string file)
            {
                this->read_data_file();
                this->read_input_file(file);                
            }
    };

    std::string trim(const std::string& str)
    {
        size_t start = 0;
        size_t end = str.length();

        while (start < end && std::isspace(str[start]))
        {
            start++;
        }
        while (end > start && std::isspace(str[end - 1]))
        {
            end--;
        }
        return str.substr(start, end - start);
    }
    
    void gate_date_value(const std::string &str, const std::string &separator, std::string &date, float &value)
    {
        size_t pos = str.find(separator);
        
        if (pos == std::string::npos)
        {
            date = trim(str);
            value = 0.0f;
        }
        else
        {
            date = trim(str.substr(0, pos));
            value = std::atof(str.substr(pos + separator.length()).c_str());
        }
    }


    bool valid_date(std::string data)
    {
        if (data.length() != 10 || data[4] != '-'|| data[7] != '-')
            return (false);
        int ano;
        int mes;
        int dia;
        
        try
        {
            ano = std::atoi(data.substr(0, 4).c_str());
            mes = std::atoi(data.substr(5, 2).c_str());
            dia = std::atoi(data.substr(8, 2).c_str());
        }
        catch(...)
        {
            return (false);
        }
        int last_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (ano < 2009 || mes <= 0 || mes > 12 || dia <= 0 || dia > last_days[mes - 1])
            return (false);
        return (true);
    }

#endif