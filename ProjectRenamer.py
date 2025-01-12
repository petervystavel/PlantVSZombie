import os
import sys

def replace_in_file(file_path, old_name, new_name):
    """Remplace toutes les occurrences de l'ancien nom par le nouveau dans un fichier."""
    with open(file_path, 'r', encoding='utf-8') as file:
        content = file.read()

    updated_content = content.replace(old_name, new_name)

    with open(file_path, 'w', encoding='utf-8') as file:
        file.write(updated_content)

def rename_files_and_folders(project_dir, old_name, new_name):
    """Renomme les fichiers et dossiers contenant l'ancien nom."""
    for root, dirs, files in os.walk(project_dir, topdown=False):
        # Renommer les fichiers
        for file_name in files:
            if old_name in file_name:
                old_file_path = os.path.join(root, file_name)
                new_file_name = file_name.replace(old_name, new_name)
                new_file_path = os.path.join(root, new_file_name)
                os.rename(old_file_path, new_file_path)
                print(f"Fichier renommé : {old_file_path} -> {new_file_path}")

        # Renommer les dossiers
        for dir_name in dirs:
            if old_name in dir_name:
                old_dir_path = os.path.join(root, dir_name)
                new_dir_name = dir_name.replace(old_name, new_name)
                new_dir_path = os.path.join(root, new_dir_name)
                os.rename(old_dir_path, new_dir_path)
                print(f"Dossier renommé : {old_dir_path} -> {new_dir_path}")

def update_project_files(project_dir, old_name, new_name):
    """Met à jour les références à l'ancien nom dans les fichiers de projet."""
    for root, _, files in os.walk(project_dir):
        for file_name in files:
            if file_name.endswith(('.sln', '.vcxproj', '.filters')):
                print("changed")
                file_path = os.path.join(root, file_name)
                replace_in_file(file_path, old_name, new_name)
                print(f"Références mises à jour dans : {file_path}")

def main():
    # Vérifier les arguments
    project_dir = "./"
    old_name = "LightEngine"
    new_name = "PVZ"

    """
    if len(sys.argv) != 4:
        print("Usage : python ProjectRenamer.py <chemin_du_projet> <ancien_nom> <nouveau_nom>")
        return

    project_dir = sys.argv[1]
    old_name = sys.argv[2]
    new_name = sys.argv[3]
    """

    if not os.path.exists(project_dir):
        print(f"Le chemin spécifié n'existe pas : {project_dir}")
        return

    # Étape 1 : Renommer les fichiers et dossiers
    rename_files_and_folders(project_dir, old_name, new_name)

    # Étape 2 : Mettre à jour les fichiers de projet
    update_project_files(project_dir, old_name, new_name)

    print("Renommage du projet terminé avec succès !")

if __name__ == "__main__":
    main()