xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 82;
 -316.98645;44.31101;-93.31539;,
 -316.98641;44.31101;90.73093;,
 -316.98641;-1.00628;90.73093;,
 -316.98645;-1.00628;-93.31539;,
 -109.80219;44.31101;90.73089;,
 -109.80228;44.31101;-93.31544;,
 -109.80228;-1.00628;-93.31544;,
 -109.80219;-1.00628;90.73089;,
 -109.80228;44.31101;-93.31544;,
 97.64734;44.31101;-93.31539;,
 97.64734;-1.00628;-93.31539;,
 -109.80228;-1.00628;-93.31544;,
 97.64734;44.31101;-93.31539;,
 97.64739;44.31101;90.73093;,
 97.64739;-1.00628;90.73093;,
 97.64734;-1.00628;-93.31539;,
 97.64739;44.31101;90.73093;,
 -109.80228;44.31101;-93.31544;,
 -109.80219;44.31101;90.73089;,
 -109.80219;-1.00628;90.73089;,
 -109.80228;-1.00628;-93.31544;,
 97.64739;-1.00628;90.73093;,
 -317.29012;44.31101;90.73089;,
 -317.29021;44.31101;-93.31544;,
 -317.29021;-1.00628;-93.31544;,
 -317.29012;-1.00628;90.73089;,
 -317.29021;44.31101;-93.31544;,
 -109.84048;44.31101;-93.31539;,
 -109.84048;-1.00628;-93.31539;,
 -317.29021;-1.00628;-93.31544;,
 -109.84048;44.31101;-93.31539;,
 -109.84039;44.31101;90.73093;,
 -109.84039;-1.00628;90.73093;,
 -109.84048;-1.00628;-93.31539;,
 -109.84039;44.31101;90.73093;,
 -317.29021;44.31101;-93.31544;,
 -317.29012;44.31101;90.73089;,
 -317.29012;-1.00628;90.73089;,
 -317.29021;-1.00628;-93.31544;,
 -109.84039;-1.00628;90.73093;,
 97.81687;44.31101;90.73089;,
 97.81677;44.31101;-93.31544;,
 97.81677;-1.00628;-93.31544;,
 97.81687;-1.00628;90.73089;,
 97.81677;44.31101;-93.31544;,
 305.26692;44.31101;-93.31539;,
 305.26692;-1.00628;-93.31539;,
 97.81677;-1.00628;-93.31544;,
 305.26692;44.31101;-93.31539;,
 305.26692;44.31101;90.73093;,
 305.26692;-1.00628;90.73093;,
 305.26692;-1.00628;-93.31539;,
 305.26692;44.31101;90.73093;,
 97.81677;44.31101;-93.31544;,
 97.81687;44.31101;90.73089;,
 97.81687;-1.00628;90.73089;,
 97.81677;-1.00628;-93.31544;,
 305.26692;-1.00628;90.73093;,
 97.64739;44.31101;89.32695;,
 -109.80219;44.31101;89.32691;,
 -109.80219;-1.00628;89.32691;,
 97.64739;-1.00628;89.32695;,
 -109.80228;44.31101;90.04903;,
 97.64734;44.31101;90.04907;,
 97.64734;-1.00628;90.04907;,
 -109.80228;-1.00628;90.04903;,
 -317.29021;44.31101;90.04903;,
 -109.84048;44.31101;90.04907;,
 -109.84048;-1.00628;90.04907;,
 -317.29021;-1.00628;90.04903;,
 -109.84039;44.31101;89.32695;,
 -317.29012;44.31101;89.32691;,
 -317.29012;-1.00628;89.32691;,
 -109.84039;-1.00628;89.32695;,
 305.26692;44.31101;89.32695;,
 97.81687;44.31101;89.32691;,
 97.81687;-1.00628;89.32691;,
 305.26692;-1.00628;89.32695;,
 97.81677;44.31101;90.04903;,
 305.26692;44.31101;90.04907;,
 305.26692;-1.00628;90.04907;,
 97.81677;-1.00628;90.04903;;
 
 22;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;16,9,17,18;,
 4;19,20,10,21;,
 4;22,23,24,25;,
 4;26,27,28,29;,
 4;30,31,32,33;,
 4;34,27,35,36;,
 4;37,38,28,39;,
 4;40,41,42,43;,
 4;44,45,46,47;,
 4;48,49,50,51;,
 4;52,45,53,54;,
 4;55,56,46,57;,
 4;58,59,60,61;,
 4;62,63,64,65;,
 4;66,67,68,69;,
 4;70,71,72,73;,
 4;74,75,76,77;,
 4;78,79,80,81;;
 
 MeshMaterialList {
  3;
  22;
  2,
  2,
  2,
  2,
  0,
  2,
  2,
  2,
  2,
  0,
  2,
  2,
  2,
  2,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data/TEXTURE/road000.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data/TEXTURE/road001.png";
   }
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  15;
  1.000000;0.000000;-0.000000;,
  -1.000000;0.000000;0.000001;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  -0.000000;0.000000;1.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;-1.000000;,
  -0.000000;0.000000;1.000000;,
  -0.000000;0.000000;1.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;;
  22;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;0,0,0,0;,
  4;13,13,13,13;,
  4;14,14,14,14;,
  4;1,1,1,1;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;13,13,13,13;,
  4;14,14,14,14;,
  4;1,1,1,1;,
  4;5,5,5,5;,
  4;6,6,6,6;,
  4;13,13,13,13;,
  4;14,14,14,14;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;9,9,9,9;,
  4;10,10,10,10;,
  4;11,11,11,11;,
  4;12,12,12,12;;
 }
 MeshTextureCoords {
  82;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;;
 }
}