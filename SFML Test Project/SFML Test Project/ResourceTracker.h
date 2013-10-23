// This stores all the resources the game has loaded
// There may need to be a limit placed on this to avoid overflow

// Whenever a resource is loaded, it gets added to this object
// Whenever that resource is needed again, it is pulled from here

#include "SFML/Graphics.hpp"

class ResourceTracker
{
	private:

		ResourceTracker();
		ResourceTracker(ResourceTracker const& copy);

		std::map <std::string, sf::Texture> textureMap; // The key will be the filename since that will be 100% unique

		ResourceTracker& operator=(ResourceTracker const& copy);

	public:
		static ResourceTracker& getInstance()
		{
			static ResourceTracker instance;
			return instance;
		}

		sf::Texture getTexture(std::string filename)
		{
			return textureMap[filename];
		}

		void addTexture(std::string filename, sf::Texture texture)
		{
			// Does texture need to be a new texture?  Wouldn't want all instances of a texture to be the same texture object
			textureMap[filename] = texture;
		}

		// Since every texture that is loaded needs to be added to the tracker, this function handles that
		sf::Texture loadTexture(std::string filename)
		{
			textureMap.find(filename);
			sf::Texture newTexture;

			newTexture.loadFromFile(filename);
			textureMap[filename] = newTexture;

			return newTexture;
		}
		// Load resource
};

