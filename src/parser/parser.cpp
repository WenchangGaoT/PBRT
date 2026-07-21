#include <tiny-renderer/parser/parser.h>

using json = nlohmann::json;
using namespace std;

namespace TinyRenderer {
  json JsonParser::ParseJsonFile(const string& file) {
    ifstream f(file); 
    if (!f) {
      std::cerr << "Could not open " << file << "\n"; 
      return json();
    } 
    json f_json; 
    f >> f_json;
    return f_json;
  }

  void JsonParser::ParseJsonFile(const string& file, vector<shared_ptr<Camera>>& cameras, Scene& scene) const {
    ifstream f(file); 
    if (!f) {
      std::cerr << "Could not open " << file << "\n"; 
      return;
    }
    json sceneJson;
    f >> sceneJson;

    this->SetCameras(sceneJson["cameras"], cameras);
    // this->SetScene(sceneJson["scene"], scene);
  }

  std::shared_ptr<Camera> JsonParser::InstantiateCamera(const json &cJson) const {
    CameraType cType = cJson.at("type").get<CameraType>();
    switch (cType) {
      case CameraType::Invalid: {
        throw std::runtime_error("Invalid camera type");
        break;
      }
      case CameraType::Pinhole: {
        Point2<double> fSize = cJson.at("film_size").get<Point2<double>>();
        CameraInitPose cip(
          cJson.at("position").get<Point3<double>>(), 
          cJson.at("z").get<Vector3<double>>(), 
          cJson.at("y").get<Vector3<double>>()
        );
        FilmInitParams fip(
          cJson["film"].at("resolution").get<Point2<int>>(),
          cJson["film"].at("output_file").get<std::string>()
        );
        return std::make_shared<PinholeCamera>(
          cip,
          fip, 
          fSize[0], 
          fSize[1]
        );
      }
      default: {
        throw std::runtime_error("Unsupported camera type.");
      }
    }
  }

  void JsonParser::SetCameras(const json& cJson, vector<shared_ptr<Camera>>& cameras) const{
    for (const auto& [name, camera] : cJson.items()) {
      shared_ptr<Camera> c = InstantiateCamera(camera);
      cameras.push_back(c);
    }
  }

  void JsonParser::SetScene(const json& sJson, Scene& scene) const {
    // Instantiate objects 
    for (const auto& pair : sJson["objects"]) {
      
    }
  }
}
