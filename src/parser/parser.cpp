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
      // std::cerr << "Could not open " << file << "\n"; 
      throw std::runtime_error("Could not open " + file + "\n");
    }
    json sceneJson;
    f >> sceneJson;

    this->SetCameras(sceneJson["cameras"], cameras);
    this->SetScene(sceneJson["scene"], scene);
  }

  // Camera Instantiations here
  std::shared_ptr<PinholeCamera> JsonParser::InstantiatePinholeCamera(const json& cJson) const {
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

  std::shared_ptr<Camera> JsonParser::InstantiateCamera(const json &cJson) const {
    CameraType cType = cJson.at("type").get<CameraType>();

    switch (cType) {
      case CameraType::Invalid: {
        throw std::runtime_error("Invalid camera type");
        break;
      }
      case CameraType::Pinhole: {
        return InstantiatePinholeCamera(cJson);
        // Point2<double> fSize = cJson.at("film_size").get<Point2<double>>();
        // CameraInitPose cip(
        //   cJson.at("position").get<Point3<double>>(), 
        //   cJson.at("z").get<Vector3<double>>(), 
        //   cJson.at("y").get<Vector3<double>>()
        // );
        // FilmInitParams fip(
        //   cJson["film"].at("resolution").get<Point2<int>>(),
        //   cJson["film"].at("output_file").get<std::string>()
        // );
        // return std::make_shared<PinholeCamera>(
        //   cip,
        //   fip, 
        //   fSize[0], 
        //   fSize[1]
        // );
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

  // Scene related definitions here
  void JsonParser::SetScene(const json& sJson, Scene& scene) const {
    // Instantiate objects 
    for (const auto& [name, oJson] : sJson["objects"].items()) {
      scene.AddObject(
        InstantiateShape(oJson)
      );
    }
  }

  std::shared_ptr<Sphere> JsonParser::InstantiateSphere(const json& sJson) const {
    Point3<double> pos = sJson.at("position").get<Point3<double>>();
    double radius = sJson.at("radius").get<double>();
    return std::make_shared<Sphere>(pos, radius);
  }

  std::shared_ptr<Shape> JsonParser::InstantiateShape(const json& sJson) const {
    ShapeType sType = sJson.at("type").get<ShapeType>();
    switch (sType) {
      case ShapeType::Sphere: {
        return InstantiateSphere(sJson);
      }
      default: {
        throw std::runtime_error("Uknown object of shape type");
      }
    }
  }
}
