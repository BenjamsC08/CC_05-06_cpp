# include "ICharacter.hpp"
# include "AMateria.hpp"


class Character : public ICharacter
{
	public:
		Character(std::string);
		Character(const Character &);
		Character &operator=(const Character &);
		virtual ~Character();
		virtual std::string const & getName() const;
		virtual void equip(AMateria*);
		virtual void unequip(int);
		virtual void use(int, ICharacter&);
		virtual void use(std::string, ICharacter&);

	private:
		std::string _name;
		AMateria	**_inventory;
		int			_equip;
		AMateria	**_trash;
		int			_trash_size;
	

};
