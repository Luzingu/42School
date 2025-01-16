/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:11:24 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/09 16:11:25 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string found_replace(std::string line, std::string found, std::string replace)
{
    std::string result;
    size_t pos = 0;
    size_t found_pos = line.find(found, pos);

    while (found_pos != std::string::npos)
    {
        result += line.substr(pos, found_pos - pos);
        result += replace;
        pos = found_pos + found.length();
        found_pos = line.find(found, pos);
    }
    result += line.substr(pos);
    return (result);
}

int main(int argc, char **argv)
{
	if(argc != 4)
	{
		std::cout << "Entrada Incorrecta.";
		return (0);
	}
	std::ifstream file(argv[1]);
	if (!file.is_open())
	{
		std::cout << "Erro ao abrir o arquivo.";
		return (0);
	}
	std::fstream novo_arquivo(std::string(argv[1]) + ".replace", std::ios::out | std::ios::trunc);
	if(!novo_arquivo.is_open())
	{
		std::cout << "Nao foi possivel criar o arquivo.";
		return (0);
	}
	std::string line;
	while (std::getline(file, line))
	{
		novo_arquivo << found_replace(line, std::string(argv[2]), std::string(argv[3])) + "\n";
	}
	novo_arquivo.close();
	file.close();
	return (0);
}