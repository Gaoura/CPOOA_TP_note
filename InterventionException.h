#pragma once

#include <iostream>
#include <exception>
#include <string>

/**
Classe destin�e � g�rer les exceptions du TP note
*/
class InterventionException : public std::exception
{
	std::string _msg;	// message de l'exception

public:

	virtual const char* what() const throw()
	{
		return _msg.c_str();
	}

	/**
	Construction de l'exception avec son message
	*/
	InterventionException(const std::string msg) :_msg(msg)	{}

	/**
	Getter pour acc�der au message
	*/
	const std::string getMsg() const
	{
		return _msg;
	}

	friend std::ostream & operator << (std::ostream &, const InterventionException &);

};

/**
Fonction de surcharge pour l'affichage <<
*/
extern std::ostream & operator << (std::ostream &, const InterventionException &);
